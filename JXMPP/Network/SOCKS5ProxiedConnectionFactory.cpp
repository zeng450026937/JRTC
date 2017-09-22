/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Network/SOCKS5ProxiedConnectionFactory.h>

#include <JXMPP/Network/SOCKS5ProxiedConnection.h>

namespace JXMPP {

SOCKS5ProxiedConnectionFactory::SOCKS5ProxiedConnectionFactory(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort) : resolver_(resolver), connectionFactory_(connectionFactory), timerFactory_(timerFactory), proxyHost_(proxyHost), proxyPort_(proxyPort) {
}

std::shared_ptr<Connection> SOCKS5ProxiedConnectionFactory::createConnection() {
    return SOCKS5ProxiedConnection::create(resolver_, connectionFactory_, timerFactory_, proxyHost_, proxyPort_);
}

}