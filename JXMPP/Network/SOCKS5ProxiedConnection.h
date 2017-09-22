#ifndef JXMPP_SOCKS5PROXIEDCONNECTION_H
#define JXMPP_SOCKS5PROXIEDCONNECTION_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Network/ProxiedConnection.h>

namespace JXMPP {
    class ConnectionFactory;
    class DomainNameResolver;
    class TimerFactory;

    class JXMPP_API SOCKS5ProxiedConnection : public ProxiedConnection {
        public:
            typedef std::shared_ptr<SOCKS5ProxiedConnection> ref;

            static ref create(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort) {
                return ref(new SOCKS5ProxiedConnection(resolver, connectionFactory, timerFactory, proxyHost, proxyPort));
            }

        private:
            SOCKS5ProxiedConnection(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort);

            virtual void initializeProxy();
            virtual void handleProxyInitializeData(std::shared_ptr<SafeByteArray> data);

        private:
            enum {
                Initial = 0,
                ProxyAuthenticating,
                ProxyConnecting
            } proxyState_;
    };
}

#endif // JXMPP_SOCKS5PROXIEDCONNECTION_H
