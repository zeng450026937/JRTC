#ifndef JXMPP_SESSION_H
#define JXMPP_SESSION_H

#include <memory>

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Elements/ToplevelElement.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/StreamStack/ConnectionLayer.h>

namespace JXMPP {
    class ProtocolHeader;
    class StreamStack;
    class PayloadParserFactoryCollection;
    class PayloadSerializerCollection;
    class XMPPLayer;
    class XMLParserFactory;

    class JXMPP_API Session : public std::enable_shared_from_this<Session> {
        public:
            enum SessionError {
                ConnectionReadError,
                ConnectionWriteError,
                XMLError,
                AuthenticationFailedError,
                NoSupportedAuthMechanismsError,
                UnexpectedElementError,
                ResourceBindError,
                SessionStartError,
                TLSError,
                ClientCertificateLoadError,
                ClientCertificateError
            };

            Session(
                    std::shared_ptr<Connection> connection,
                    PayloadParserFactoryCollection* payloadParserFactories,
                    PayloadSerializerCollection* payloadSerializers,
                    XMLParserFactory* xmlParserFactory);
            virtual ~Session();

            void startSession();
            void finishSession();

            void sendElement(std::shared_ptr<ToplevelElement>);

            const JID& getLocalJID() const {
                return localJID;
            }

            const JID& getRemoteJID() const {
                return remoteJID;
            }

            boost::signals2::signal<void (std::shared_ptr<ToplevelElement>)> onElementReceived;
            boost::signals2::signal<void (const boost::optional<SessionError>&)> onSessionFinished;
            boost::signals2::signal<void (const SafeByteArray&)> onDataWritten;
            boost::signals2::signal<void (const SafeByteArray&)> onDataRead;

        protected:
            void setRemoteJID(const JID& j) {
                remoteJID = j;
            }

            void setLocalJID(const JID& j) {
                localJID = j;
            }

            void finishSession(const SessionError&);

            virtual void handleSessionStarted() {}
            virtual void handleSessionFinished(const boost::optional<SessionError>&) {}
            virtual void handleElement(std::shared_ptr<ToplevelElement>) = 0;
            virtual void handleStreamStart(const ProtocolHeader&) = 0;

            void initializeStreamStack();

            XMPPLayer* getXMPPLayer() const {
                return xmppLayer;
            }

            StreamStack* getStreamStack() const {
                return streamStack;
            }

            void setFinished();

        private:
            void handleDisconnected(const boost::optional<Connection::Error>& error);

        private:
            JID localJID;
            JID remoteJID;
            std::shared_ptr<Connection> connection;
            PayloadParserFactoryCollection* payloadParserFactories;
            PayloadSerializerCollection* payloadSerializers;
            XMLParserFactory* xmlParserFactory;
            XMPPLayer* xmppLayer;
            ConnectionLayer* connectionLayer;
            StreamStack* streamStack;
            bool finishing;
    };
}

#endif // JXMPP_SESSION_H