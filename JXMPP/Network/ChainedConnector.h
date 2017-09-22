#ifndef JXMPP_CHAINEDCONNECTOR_H
#define JXMPP_CHAINEDCONNECTOR_H

#include <deque>
#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Error.h>

namespace JXMPP {
    class Connection;
    class Connector;
    class ConnectionFactory;
    class TimerFactory;
    class DomainNameResolver;

    class JXMPP_API ChainedConnector {
        public:
            ChainedConnector(const std::string& hostname, int port, const boost::optional<std::string>& serviceLookupPrefix, DomainNameResolver*, const std::vector<ConnectionFactory*>&, TimerFactory*);
            ~ChainedConnector();

            void setTimeoutMilliseconds(int milliseconds);
            void start();
            void stop();

            boost::signals2::signal<void (std::shared_ptr<Connection>, std::shared_ptr<Error>)> onConnectFinished;

        private:
            void finish(std::shared_ptr<Connection> connection, std::shared_ptr<Error>);
            void tryNextConnectionFactory();
            void handleConnectorFinished(std::shared_ptr<Connection>, std::shared_ptr<Error>);

        private:
            std::string hostname;
            int port;
            boost::optional<std::string> serviceLookupPrefix;
            DomainNameResolver* resolver;
            std::vector<ConnectionFactory*> connectionFactories;
            TimerFactory* timerFactory;
            int timeoutMilliseconds;
            std::deque<ConnectionFactory*> connectionFactoryQueue;
            std::shared_ptr<Connector> currentConnector;
            std::shared_ptr<Error> lastError;
    };
}

#endif // JXMPP_CHAINEDCONNECTOR_H
