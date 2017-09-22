#ifndef JXMPP_COMPONENTCONNECTOR_H
#define JXMPP_COMPONENTCONNECTOR_H

#include <deque>
#include <memory>
#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/Network/DomainNameResolveError.h>
#include <JXMPP/Network/HostAddressPort.h>
#include <JXMPP/Network/Timer.h>

namespace JXMPP {
    class DomainNameAddressQuery;
    class DomainNameResolver;
    class ConnectionFactory;
    class TimerFactory;

    class JXMPP_API ComponentConnector : public boost::signals2::trackable, public std::enable_shared_from_this<ComponentConnector> {
        public:
            typedef std::shared_ptr<ComponentConnector> ref;

            static ComponentConnector::ref create(const std::string& hostname, int port, DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory) {
                return ref(new ComponentConnector(hostname, port, resolver, connectionFactory, timerFactory));
            }

            void setTimeoutMilliseconds(int milliseconds);

            void start();
            void stop();

            boost::signals2::signal<void (std::shared_ptr<Connection>)> onConnectFinished;

        private:
            ComponentConnector(const std::string& hostname, int port, DomainNameResolver*, ConnectionFactory*, TimerFactory*);

            void handleAddressQueryResult(const std::vector<HostAddress>& address, boost::optional<DomainNameResolveError> error);
            void tryNextAddress();
            void tryConnect(const HostAddressPort& target);

            void handleConnectionConnectFinished(bool error);
            void finish(std::shared_ptr<Connection>);
            void handleTimeout();


        private:
            std::string hostname;
            int port;
            DomainNameResolver* resolver;
            ConnectionFactory* connectionFactory;
            TimerFactory* timerFactory;
            int timeoutMilliseconds;
            std::shared_ptr<Timer> timer;
            std::shared_ptr<DomainNameAddressQuery> addressQuery;
            std::deque<HostAddress> addressQueryResults;
            std::shared_ptr<Connection> currentConnection;
    };
}

#endif // JXMPP_COMPONENTCONNECTOR_H
