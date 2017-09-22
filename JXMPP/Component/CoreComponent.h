#ifndef JXMPP_CORECOMPONENT_H
#define JXMPP_CORECOMPONENT_H

#include <memory>
#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Error.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Component/ComponentConnector.h>
#include <JXMPP/Component/ComponentError.h>
#include <JXMPP/Component/ComponentSession.h>
#include <JXMPP/Component/ComponentSessionStanzaChannel.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/Entity/Entity.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Parser/PayloadParsers/FullPayloadParserFactoryCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/FullPayloadSerializerCollection.h>

namespace JXMPP {
    class BasicSessionStream;
    class ComponentSession;
    class IQRouter;
    class NetworkFactories;

    /**
     * The central class for communicating with an XMPP server as a component.
     *
     * This class is responsible for setting up the connection with the XMPP
     * server and authenticating the component.
     *
     * This class can be used directly in your application, although the Component
     * subclass provides more functionality and interfaces, and is better suited
     * for most needs.
     */
    class JXMPP_API CoreComponent : public Entity {
        public:
            CoreComponent(const JID& jid, const std::string& secret, NetworkFactories* networkFactories);
            virtual ~CoreComponent();

            void connect(const std::string& host, int port);
            void disconnect();

            void sendMessage(std::shared_ptr<Message>);
            void sendPresence(std::shared_ptr<Presence>);
            void sendData(const std::string& data);

            IQRouter* getIQRouter() const {
                return iqRouter_;
            }

            StanzaChannel* getStanzaChannel() const {
                return stanzaChannel_;
            }

            bool isAvailable() const {
                return stanzaChannel_->isAvailable();
            }

            /**
             * Returns the JID of the component
             */
            const JID& getJID() const {
                return jid_;
            }

        public:
            boost::signals2::signal<void (const ComponentError&)> onError;
            boost::signals2::signal<void ()> onConnected;
            boost::signals2::signal<void (const SafeByteArray&)> onDataRead;
            boost::signals2::signal<void (const SafeByteArray&)> onDataWritten;

            boost::signals2::signal<void (std::shared_ptr<Message>)> onMessageReceived;
            boost::signals2::signal<void (std::shared_ptr<Presence>) > onPresenceReceived;

        private:
            void handleConnectorFinished(std::shared_ptr<Connection>);
            void handleStanzaChannelAvailableChanged(bool available);
            void handleSessionFinished(std::shared_ptr<Error>);
            void handleDataRead(const SafeByteArray&);
            void handleDataWritten(const SafeByteArray&);

        private:
            NetworkFactories* networkFactories;
            JID jid_;
            std::string secret_;
            ComponentSessionStanzaChannel* stanzaChannel_;
            IQRouter* iqRouter_;
            ComponentConnector::ref connector_;
            std::shared_ptr<Connection> connection_;
            std::shared_ptr<BasicSessionStream> sessionStream_;
            std::shared_ptr<ComponentSession> session_;
            bool disconnectRequested_;
    };
}

#endif // JXMPP_CORECOMPONENT_H
