#ifndef JXMPP_CLIENTSESSIONSTANZACHANNEL_H
#define JXMPP_CLIENTSESSIONSTANZACHANNEL_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/IDGenerator.h>
#include <JXMPP/Client/ClientSession.h>
#include <JXMPP/Client/StanzaChannel.h>
#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Elements/Presence.h>

namespace JXMPP {
    /**
     * StanzaChannel implementation around a ClientSession.
     */
    class JXMPP_API ClientSessionStanzaChannel : public StanzaChannel {
        public:
            virtual ~ClientSessionStanzaChannel();

            void setSession(std::shared_ptr<ClientSession> session);

            void sendIQ(std::shared_ptr<IQ> iq);
            void sendMessage(std::shared_ptr<Message> message);
            void sendPresence(std::shared_ptr<Presence> presence);
            bool getStreamManagementEnabled() const;
            virtual std::vector<Certificate::ref> getPeerCertificateChain() const;

            bool isAvailable() const {
                return session && session->getState() == ClientSession::State::Initialized;
            }

        private:
            std::string getNewIQID();
            void send(std::shared_ptr<Stanza> stanza);
            void handleSessionFinished(std::shared_ptr<Error> error);
            void handleStanza(std::shared_ptr<Stanza> stanza);
            void handleStanzaAcked(std::shared_ptr<Stanza> stanza);
            void handleSessionInitialized();

        private:
            IDGenerator idGenerator;
            std::shared_ptr<ClientSession> session;
    };

}

#endif // JXMPP_CLIENTSESSIONSTANZACHANNEL_H
