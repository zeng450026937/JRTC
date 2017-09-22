#ifndef JXMPP_PROXIEDCONNECTION_H
#define JXMPP_PROXIEDCONNECTION_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeString.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/Network/Connector.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class ConnectionFactory;

    class JXMPP_API ProxiedConnection : public Connection, public std::enable_shared_from_this<ProxiedConnection> {
        public:
            ProxiedConnection(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort);
            virtual ~ProxiedConnection();

            virtual void listen();
            virtual void connect(const HostAddressPort& address);
            virtual void disconnect();
            virtual void write(const SafeByteArray& data);

            virtual HostAddressPort getLocalAddress() const;
            virtual HostAddressPort getRemoteAddress() const;

        private:
            void handleConnectFinished(Connection::ref connection);
            void handleDataRead(std::shared_ptr<SafeByteArray> data);
            void handleDisconnected(const boost::optional<Error>& error);
            void cancelConnector();

        protected:
            void setProxyInitializeFinished(bool success);

            virtual void initializeProxy() = 0;
            virtual void handleProxyInitializeData(std::shared_ptr<SafeByteArray> data) = 0;

            const HostAddressPort& getServer() const {
                return server_;
            }

            void reconnect();

        private:
            bool connected_;
            DomainNameResolver* resolver_;
            ConnectionFactory* connectionFactory_;
            TimerFactory* timerFactory_;
            std::string proxyHost_;
            int proxyPort_;
            HostAddressPort server_;
            Connector::ref connector_;
            std::shared_ptr<Connection> connection_;
    };
}

#endif // JXMPP_PROXIEDCONNECTION_H
