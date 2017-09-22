#ifndef JXMPP_STANZACHANNEL_H
#define JXMPP_STANZACHANNEL_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/Queries/IQChannel.h>
#include <JXMPP/TLS/Certificate.h>

namespace JXMPP {
    class JXMPP_API StanzaChannel : public IQChannel {
        public:
            virtual void sendMessage(std::shared_ptr<Message>) = 0;
            virtual void sendPresence(std::shared_ptr<Presence>) = 0;
            virtual bool isAvailable() const = 0;
            virtual bool getStreamManagementEnabled() const = 0;
            virtual std::vector<Certificate::ref> getPeerCertificateChain() const = 0;

            boost::signals2::signal<void (bool /* isAvailable */)> onAvailableChanged;
            boost::signals2::signal<void (std::shared_ptr<Message>)> onMessageReceived;
            boost::signals2::signal<void (std::shared_ptr<Presence>) > onPresenceReceived;
            boost::signals2::signal<void (std::shared_ptr<Stanza>)> onStanzaAcked;
    };
}

#endif // JXMPP_STANZACHANNEL_H
