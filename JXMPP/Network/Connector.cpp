#include <JXMPP/Network/Connector.h>

#include <boost/bind.hpp>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Network/ConnectionFactory.h>
#include <JXMPP/Network/DomainNameAddressQuery.h>
#include <JXMPP/Network/DomainNameResolver.h>
#include <JXMPP/Network/HostAddress.h>
#include <JXMPP/Network/TimerFactory.h>

namespace JXMPP {

Connector::Connector(const std::string& hostname, int port, const boost::optional<std::string>& serviceLookupPrefix, DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory) : hostname(hostname), port(port), serviceLookupPrefix(serviceLookupPrefix), resolver(resolver), connectionFactory(connectionFactory), timerFactory(timerFactory), timeoutMilliseconds(0), queriedAllServices(true), foundSomeDNS(false) {
}

void Connector::setTimeoutMilliseconds(int milliseconds) {
    timeoutMilliseconds = milliseconds;
}

void Connector::start() {
    JXMPP_LOG(debug) << "Starting connector for " << hostname << std::endl;
    assert(!currentConnection);
    assert(!serviceQuery);
    assert(!timer);
    queriedAllServices = false;
    auto hostAddress = HostAddress::fromString(hostname);
    if (timeoutMilliseconds > 0) {
        timer = timerFactory->createTimer(timeoutMilliseconds);
        timer->onTick.connect(boost::bind(&Connector::handleTimeout, shared_from_this()));
    }
    if (serviceLookupPrefix) {
        serviceQuery = resolver->createServiceQuery(*serviceLookupPrefix, hostname);
        serviceQuery->onResult.connect(boost::bind(&Connector::handleServiceQueryResult, shared_from_this(), _1));
        serviceQuery->run();
    }
    else if (hostAddress) {
        // hostname is already a valid address; skip name lookup.
        foundSomeDNS = true;
        addressQueryResults.push_back(hostAddress.get());
        tryNextAddress();
    } else {
        queryAddress(hostname);
    }
}

void Connector::stop() {
    if (currentConnection) {
        currentConnection->onConnectFinished.disconnect(boost::bind(&Connector::handleConnectionConnectFinished, shared_from_this(), _1));
        currentConnection->disconnect();
    }
    finish(std::shared_ptr<Connection>());
}

void Connector::queryAddress(const std::string& hostname) {
    assert(!addressQuery);
    addressQuery = resolver->createAddressQuery(hostname);
    addressQuery->onResult.connect(boost::bind(&Connector::handleAddressQueryResult, shared_from_this(), _1, _2));
    addressQuery->run();
}

void Connector::handleServiceQueryResult(const std::vector<DomainNameServiceQuery::Result>& result) {
    JXMPP_LOG(debug) << result.size() << " SRV result(s)" << std::endl;
    serviceQueryResults = std::deque<DomainNameServiceQuery::Result>(result.begin(), result.end());
    serviceQuery.reset();
    if (!serviceQueryResults.empty()) {
        foundSomeDNS = true;
    }
    tryNextServiceOrFallback();
}

void Connector::tryNextServiceOrFallback() {
    if (queriedAllServices) {
        JXMPP_LOG(debug) << "Queried all services" << std::endl;
        finish(std::shared_ptr<Connection>());
    }
    else if (serviceQueryResults.empty()) {
        JXMPP_LOG(debug) << "Falling back on A resolution" << std::endl;
        // Fall back on simple address resolving
        queriedAllServices = true;
        queryAddress(hostname);
    }
    else {
        JXMPP_LOG(debug) << "Querying next address" << std::endl;
        queryAddress(serviceQueryResults.front().hostname);
    }
}

void Connector::handleAddressQueryResult(const std::vector<HostAddress>& addresses, boost::optional<DomainNameResolveError> error) {
    JXMPP_LOG(debug) << addresses.size() << " addresses" << std::endl;
    addressQuery.reset();
    if (error || addresses.empty()) {
        if (!serviceQueryResults.empty()) {
            serviceQueryResults.pop_front();
        }
        tryNextServiceOrFallback();
    }
    else {
        foundSomeDNS = true;
        addressQueryResults = std::deque<HostAddress>(addresses.begin(), addresses.end());
        tryNextAddress();
    }
}

void Connector::tryNextAddress() {
    if (addressQueryResults.empty()) {
        JXMPP_LOG(debug) << "Done trying addresses. Moving on." << std::endl;
        // Done trying all addresses. Move on to the next host.
        if (!serviceQueryResults.empty()) {
            serviceQueryResults.pop_front();
        }
        tryNextServiceOrFallback();
    }
    else {
        JXMPP_LOG(debug) << "Trying next address" << std::endl;
        HostAddress address = addressQueryResults.front();
        addressQueryResults.pop_front();

        int connectPort = (port == -1 ? 5222 : port);
        if (!serviceQueryResults.empty()) {
            connectPort = serviceQueryResults.front().port;
        }

        tryConnect(HostAddressPort(address, connectPort));
    }
}

void Connector::tryConnect(const HostAddressPort& target) {
    assert(!currentConnection);
    JXMPP_LOG(debug) << "Trying to connect to " << target.getAddress().toString() << ":" << target.getPort() << std::endl;
    currentConnection = connectionFactory->createConnection();
    currentConnection->onConnectFinished.connect(boost::bind(&Connector::handleConnectionConnectFinished, shared_from_this(), _1));
    currentConnection->connect(target);
    if (timer) {
        timer->start();
    }
}

void Connector::handleConnectionConnectFinished(bool error) {
    JXMPP_LOG(debug) << "ConnectFinished: " << (error ? "error" : "success") << std::endl;
    if (timer) {
            timer->stop();
            timer.reset();
    }
    currentConnection->onConnectFinished.disconnect(boost::bind(&Connector::handleConnectionConnectFinished, shared_from_this(), _1));
    if (error) {
        currentConnection.reset();
        if (!addressQueryResults.empty()) {
            tryNextAddress();
        }
        else {
            if (!serviceQueryResults.empty()) {
                serviceQueryResults.pop_front();
            }
            tryNextServiceOrFallback();
        }
    }
    else {
        finish(currentConnection);
    }
}

void Connector::finish(std::shared_ptr<Connection> connection) {
    if (timer) {
        timer->stop();
        timer->onTick.disconnect(boost::bind(&Connector::handleTimeout, shared_from_this()));
        timer.reset();
    }
    if (serviceQuery) {
        serviceQuery->onResult.disconnect(boost::bind(&Connector::handleServiceQueryResult, shared_from_this(), _1));
        serviceQuery.reset();
    }
    if (addressQuery) {
        addressQuery->onResult.disconnect(boost::bind(&Connector::handleAddressQueryResult, shared_from_this(), _1, _2));
        addressQuery.reset();
    }
    if (currentConnection) {
        currentConnection->onConnectFinished.disconnect(boost::bind(&Connector::handleConnectionConnectFinished, shared_from_this(), _1));
        currentConnection.reset();
    }
    onConnectFinished(connection, (connection || foundSomeDNS) ? std::shared_ptr<Error>() : std::make_shared<DomainNameResolveError>());
}

void Connector::handleTimeout() {
    JXMPP_LOG(debug) << "Timeout" << std::endl;
    handleConnectionConnectFinished(true);
}

}
