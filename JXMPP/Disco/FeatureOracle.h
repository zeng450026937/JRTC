#ifndef JXMPP_FEATUREORACLE_H
#define JXMPP_FEATUREORACLE_H

#include <unordered_map>
#include <unordered_set>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Tristate.h>
#include <JXMPP/Elements/DiscoInfo.h>

namespace JXMPP {

class EntityCapsProvider;
class JID;
class PresenceOracle;

/**
 * @brief The FeatureOracle class enables direct feature support lookup for client features supported by Swiften.
 */
class JXMPP_API FeatureOracle {
    public:
        FeatureOracle(EntityCapsProvider* capsProvider, PresenceOracle* presenceOracle);

    public:
        Tristate isFileTransferSupported(const JID& jid);
        Tristate isMessageReceiptsSupported(const JID& jid);
        Tristate isMessageCorrectionSupported(const JID& jid);
        Tristate isWhiteboardSupported(const JID& jid);

        JID getMostAvailableClientForFileTrasfer(const JID& bareJID);

    private:
        /**
         * @brief getDiscoResultForJID returns a  shared reference to a DiscoInfo representing features supported by the jid.
         * @param jid The JID to return an std::unordered_map<std::string, Tristate> for.
         * @return std::unordered_map<std::string, Tristate>
         */
        std::unordered_map<std::string, Tristate> getFeaturesForJID(const JID& jid);

        Tristate isFeatureSupported(const std::unordered_map<std::string, Tristate>& supportedFeatures, const std::string& feature);

    private:
        EntityCapsProvider* capsProvider_;
        PresenceOracle* presenceOracle_;
};

}

#endif // JXMPP_FEATUREORACLE_H
