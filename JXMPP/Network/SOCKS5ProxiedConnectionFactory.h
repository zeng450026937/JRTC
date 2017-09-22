#ifndef JXMPP_SOCKS5PROXIEDCONNECTIONFACTORY_H
#define JXMPP_SOCKS5PROXIEDCONNECTIONFACTORY_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Network/ConnectionFactory.h>
#include <JXMPP/Network/HostAddressPort.h>
#include <JXMPP/Network/HostNameOrAddress.h>

namespace JXMPP {
    class DomainNameResolver;
    class TimerFactory;

    class JXMPP_API SOCKS5ProxiedConnectionFactory : public ConnectionFactory {
        public:
            SOCKS5ProxiedConnectionFactory(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort);

            virtual std::shared_ptr<Connection> createConnection();

        private:
            DomainNameResolver* resolver_;
            ConnectionFactory* connectionFactory_;
            TimerFactory* timerFactory_;
            std::string proxyHost_;
            int proxyPort_;
    };
}

#endif // JXMPP_SOCKS5PROXIEDCONNECTIONFACTORY_H
