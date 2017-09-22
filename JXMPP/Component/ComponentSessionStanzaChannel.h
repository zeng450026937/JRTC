#ifndef JXMPP_COMPONENTSESSIONSTANZACHANNEL_H
#define JXMPP_COMPONENTSESSIONSTANZACHANNEL_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/IDGenerator.h>
#include <JXMPP/Client/StanzaChannel.h>
#include <JXMPP/Component/ComponentSession.h>
#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Elements/Presence.h>

namespace JXMPP {
    /**
     * StanzaChannel implementation around a ComponentSession.
     */
    class JXMPP_API ComponentSessionStanzaChannel : public StanzaChannel {
        public:
            virtual ~ComponentSessionStanzaChannel();

            void setSession(std::shared_ptr<ComponentSession> session);

            void sendIQ(std::shared_ptr<IQ> iq);
            void sendMessage(std::shared_ptr<Message> message);
            void sendPresence(std::shared_ptr<Presence> presence);

            bool getStreamManagementEnabled() const {
                return false;
            }

            std::vector<Certificate::ref> getPeerCertificateChain() const {
                // TODO: actually implement this method
                return std::vector<Certificate::ref>();
            }

            bool isAvailable() const {
                return session && session->getState() == ComponentSession::Initialized;
            }

        private:
            std::string getNewIQID();
            void send(std::shared_ptr<Stanza> stanza);
            void handleSessionFinished(std::shared_ptr<Error> error);
            void handleStanza(std::shared_ptr<Stanza> stanza);
            void handleSessionInitialized();

        private:
            IDGenerator idGenerator;
            std::shared_ptr<ComponentSession> session;
    };

}

#endif // JXMPP_COMPONENTSESSIONSTANZACHANNEL_H
