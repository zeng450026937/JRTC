#include <JXMPP/Disco/FeatureOracle.h>

#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <vector>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Disco/EntityCapsProvider.h>
#include <JXMPP/Elements/Idle.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/FileTransfer/FileTransferManager.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Presence/PresenceOracle.h>

namespace JXMPP {

FeatureOracle::FeatureOracle(EntityCapsProvider* capsProvider, PresenceOracle* presenceOracle) : capsProvider_(capsProvider), presenceOracle_(presenceOracle) {
}

Tristate FeatureOracle::isFileTransferSupported(const JID& jid) {
    Tristate fileTransferSupported = No;

    auto isYesOrMaybe = [](Tristate tristate) { return tristate == Yes || tristate == Maybe; };
    auto isYes = [](Tristate tristate) { return tristate == Yes; };

    auto supportedFeatures = getFeaturesForJID(jid);

    auto jingleSupported = isFeatureSupported(supportedFeatures, DiscoInfo::JingleFeature);
    auto jingleFTSupported = isFeatureSupported(supportedFeatures, DiscoInfo::JingleFTFeature);
    auto jingleTransportIBBSupported = isFeatureSupported(supportedFeatures, DiscoInfo::JingleTransportsIBBFeature);
    auto jingleTransportS5BSupported = isFeatureSupported(supportedFeatures, DiscoInfo::JingleTransportsS5BFeature);

    if (isYes(jingleSupported) && isYes(jingleFTSupported) && (isYes(jingleTransportIBBSupported) || isYes(jingleTransportS5BSupported))) {
        fileTransferSupported = Yes;
    }
    else if (isYesOrMaybe(jingleSupported) && isYesOrMaybe(jingleFTSupported) && (isYesOrMaybe(jingleTransportIBBSupported) || isYesOrMaybe(jingleTransportS5BSupported))) {
        fileTransferSupported = Maybe;
    }

    return fileTransferSupported;
}

Tristate FeatureOracle::isMessageReceiptsSupported(const JID& jid) {
    return isFeatureSupported(getFeaturesForJID(jid), DiscoInfo::MessageDeliveryReceiptsFeature);
}

Tristate FeatureOracle::isMessageCorrectionSupported(const JID& jid) {
    return isFeatureSupported(getFeaturesForJID(jid), DiscoInfo::MessageCorrectionFeature);
}

Tristate FeatureOracle::isWhiteboardSupported(const JID& jid) {
    return isFeatureSupported(getFeaturesForJID(jid), DiscoInfo::WhiteboardFeature);
}

class PresenceFeatureAvailablityComparator {
    public:
        static int preferenceFromStatusShow(StatusShow::Type showType) {
            switch (showType) {
                case StatusShow::FFC:
                    return 5;
                case StatusShow::Online:
                    return 4;
                case StatusShow::DND:
                    return 3;
                case StatusShow::Away:
                    return 2;
                case StatusShow::XA:
                    return 1;
                case StatusShow::None:
                    return 0;
            }
            assert(false);
            return -1;
        }

        static int compareWithoutResource(const Presence::ref& a, const Presence::ref& b) {
            int aPreference = preferenceFromStatusShow(a->getShow());
            int bPreference = preferenceFromStatusShow(b->getShow());

            if (aPreference != bPreference) {
                return aPreference < bPreference ? 1 : -1;
            }

            Idle::ref aIdle = a->getPayload<Idle>();
            Idle::ref bIdle = b->getPayload<Idle>();

            if (aIdle && !bIdle) {
                return -1;
            }
            else if (!aIdle && bIdle) {
                return 1;
            }

            if (a->getPriority() != b->getPriority()) {
                return a->getPriority() < b->getPriority() ? 1 : -1;
            }

            return 0;
        }

        /*
         * This method returns true, if \ref Presence \p b is more available than
         * \ref Presence \p a.
         * Going by \ref StatusShow::Type first, then by idle state, then by
         * presence priority and finally by resource name.
         */
        bool operator()(const Presence::ref& a, const Presence::ref& b) {
            int aMoreAvailableThanB = compareWithoutResource(a, b);
            if (aMoreAvailableThanB < 0) {
                return true;
            }
            else if (aMoreAvailableThanB > 0) {
                return false;
            }

            return a->getFrom().getResource() < b->getFrom().getResource();
        }
};

JID FeatureOracle::getMostAvailableClientForFileTrasfer(const JID& bareJID) {
    JID fullJID;
    assert(bareJID.isBare());

    std::vector<Presence::ref> allPresences =  presenceOracle_->getAllPresence(bareJID);
    std::sort(allPresences.begin(), allPresences.end(), PresenceFeatureAvailablityComparator());

    for (const auto& presence : allPresences) {
        if (presence->isAvailable()) {
            if (isFileTransferSupported(presence->getFrom()) == Yes) {
                fullJID = presence->getFrom();
                break;
            }
        }
    }

    JXMPP_LOG_ASSERT(!fullJID.isBare(), error);
    return fullJID;
}

std::unordered_map<std::string, Tristate> FeatureOracle::getFeaturesForJID(const JID& jid) {
    std::unordered_map<std::string, Tristate> supportedFeatures;
    if (jid.isBare()) {
        // Calculate the union of disco features of all most available results and return that.
        std::vector<DiscoInfo::ref> onlineDiscoInfos;
        std::unordered_set<std::string> features;

        // Collect relevant disco info results and the set of features.
        for (auto&& presence : presenceOracle_->getAllPresence(jid)) {
            if (presence->getType() == Presence::Available) {
                DiscoInfo::ref presenceDiscoInfo = capsProvider_->getCapsCached(presence->getFrom());
                if (presenceDiscoInfo) {
                    onlineDiscoInfos.push_back(presenceDiscoInfo);
                    features.insert(presenceDiscoInfo->getFeatures().begin(), presenceDiscoInfo->getFeatures().end());
                }
            }
        }

        // Calculate supportedFeaturesMap.
        for (auto&& feature : features) {
            Tristate supported = Yes;
            for (auto&& discoInfo : onlineDiscoInfos) {
                if (!discoInfo->hasFeature(feature)) {
                    supported = Maybe;
                    break;
                }
            }
            supportedFeatures[feature] = supported;
        }
    }
    else {
        // Return the disco result of the full JID.
        auto discoInfo = capsProvider_->getCapsCached(jid);
        if (discoInfo) {
            for (auto&& feature : discoInfo->getFeatures()) {
                supportedFeatures[feature] = Yes;
            }
        }
    }

    return supportedFeatures;
}

Tristate FeatureOracle::isFeatureSupported(const std::unordered_map<std::string, Tristate>& supportedFeatures, const std::string& feature) {
    Tristate supported = No;
    auto lookupResult = supportedFeatures.find(feature);
    if (lookupResult != supportedFeatures.end()) {
        supported = lookupResult->second;
    }
    return supported;
}

}
