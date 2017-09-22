#ifndef JXMPP_COMPONENTSESSION_H
#define JXMPP_COMPONENTSESSION_H

#include <memory>
#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Error.h>
#include <JXMPP/Elements/Stanza.h>
#include <JXMPP/Elements/ToplevelElement.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Session/SessionStream.h>

namespace JXMPP {
    class CryptoProvider;

    class JXMPP_API ComponentSession : public std::enable_shared_from_this<ComponentSession> {
        public:
            enum State {
                Initial,
                WaitingForStreamStart,
                Authenticating,
                Initialized,
                Finishing,
                Finished
            };

            struct Error : public JXMPP::Error {
                enum Type {
                    AuthenticationFailedError,
                    UnexpectedElementError
                } type;
                Error(Type type) : type(type) {}
            };

            ~ComponentSession();

            static std::shared_ptr<ComponentSession> create(const JID& jid, const std::string& secret, std::shared_ptr<SessionStream> stream, CryptoProvider* crypto) {
                return std::shared_ptr<ComponentSession>(new ComponentSession(jid, secret, stream, crypto));
            }

            State getState() const {
                return state;
            }

            void start();
            void finish();

            void sendStanza(std::shared_ptr<Stanza>);

        public:
            boost::signals2::signal<void ()> onInitialized;
            boost::signals2::signal<void (std::shared_ptr<JXMPP::Error>)> onFinished;
            boost::signals2::signal<void (std::shared_ptr<Stanza>)> onStanzaReceived;

        private:
            ComponentSession(const JID& jid, const std::string& secret, std::shared_ptr<SessionStream>, CryptoProvider*);

            void finishSession(Error::Type error);
            void finishSession(std::shared_ptr<JXMPP::Error> error);

            void sendStreamHeader();

            void handleElement(std::shared_ptr<ToplevelElement>);
            void handleStreamStart(const ProtocolHeader&);
            void handleStreamClosed(std::shared_ptr<JXMPP::Error>);

            bool checkState(State);

        private:
            JID jid;
            std::string secret;
            std::shared_ptr<SessionStream> stream;
            CryptoProvider* crypto;
            std::shared_ptr<JXMPP::Error> error;
            State state;
    };
}

#endif // JXMPP_COMPONENTSESSION_H
