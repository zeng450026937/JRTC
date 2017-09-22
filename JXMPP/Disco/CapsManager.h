#ifndef JXMPP_CAPSMANAGER_H
#define JXMPP_CAPSMANAGER_H

#include <map>
#include <set>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Disco/CapsProvider.h>
#include <JXMPP/Elements/CapsInfo.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/Presence.h>

namespace JXMPP {
    class StanzaChannel;
    class IQRouter;
    class JID;
    class CapsStorage;
    class CryptoProvider;

    class JXMPP_API CapsManager : public CapsProvider, public boost::signals2::trackable {
        public:
            CapsManager(CapsStorage*, StanzaChannel*, IQRouter*, CryptoProvider*);

            DiscoInfo::ref getCaps(const std::string&) const;

            // Mainly for testing purposes
            void setWarnOnInvalidHash(bool b) {
                warnOnInvalidHash = b;
            }

        private:
            void handlePresenceReceived(std::shared_ptr<Presence>);
            void handleStanzaChannelAvailableChanged(bool);
            void handleDiscoInfoReceived(const JID&, const std::string& hash, DiscoInfo::ref, ErrorPayload::ref);
            void requestDiscoInfo(const JID& jid, const std::string& node, const std::string& hash);

        private:
            IQRouter* iqRouter;
            CryptoProvider* crypto;
            CapsStorage* capsStorage;
            bool warnOnInvalidHash;
            std::set<std::string> requestedDiscoInfos;
            std::set< std::pair<JID, std::string> > failingCaps;
            std::map<std::string, std::set< std::pair<JID, std::string> > > fallbacks;
    };
}

#endif // JXMPP_CAPSMANAGER_H
