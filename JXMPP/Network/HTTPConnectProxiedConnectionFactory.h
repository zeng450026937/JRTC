#ifndef JXMPP_HTTPCONNECTPROXIEDCONNECTIONFACTORY_H
#define JXMPP_HTTPCONNECTPROXIEDCONNECTIONFACTORY_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeString.h>
#include <JXMPP/Network/ConnectionFactory.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class DomainNameResolver;
    class HTTPTrafficFilter;
    class TimerFactory;

    class JXMPP_API HTTPConnectProxiedConnectionFactory : public ConnectionFactory {
        public:
            HTTPConnectProxiedConnectionFactory(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort, std::shared_ptr<HTTPTrafficFilter> httpTrafficFilter = std::shared_ptr<HTTPTrafficFilter>());
            HTTPConnectProxiedConnectionFactory(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort, const SafeString& authID, const SafeString& authPassword, std::shared_ptr<HTTPTrafficFilter> httpTrafficFilter = std::shared_ptr<HTTPTrafficFilter>());

            virtual std::shared_ptr<Connection> createConnection();

        private:
            DomainNameResolver* resolver_;
            ConnectionFactory* connectionFactory_;
            TimerFactory* timerFactory_;
            std::string proxyHost_;
            int proxyPort_;
            SafeString authID_;
            SafeString authPassword_;
            std::shared_ptr<HTTPTrafficFilter> httpTrafficFilter_;
    };
}

#endif // JXMPP_HTTPCONNECTPROXIEDCONNECTIONFACTORY_H
