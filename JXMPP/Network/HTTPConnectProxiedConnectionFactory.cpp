/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Network/HTTPConnectProxiedConnectionFactory.h>

#include <JXMPP/Network/HTTPConnectProxiedConnection.h>

namespace JXMPP {

HTTPConnectProxiedConnectionFactory::HTTPConnectProxiedConnectionFactory(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort, std::shared_ptr<HTTPTrafficFilter> httpTrafficFilter) : resolver_(resolver), connectionFactory_(connectionFactory), timerFactory_(timerFactory), proxyHost_(proxyHost), proxyPort_(proxyPort),  authID_(""), authPassword_(""), httpTrafficFilter_(httpTrafficFilter) {
}


HTTPConnectProxiedConnectionFactory::HTTPConnectProxiedConnectionFactory(DomainNameResolver* resolver, ConnectionFactory* connectionFactory, TimerFactory* timerFactory, const std::string& proxyHost, int proxyPort, const SafeString& authID, const SafeString& authPassword, std::shared_ptr<HTTPTrafficFilter> httpTrafficFilter) : resolver_(resolver), connectionFactory_(connectionFactory), timerFactory_(timerFactory), proxyHost_(proxyHost), proxyPort_(proxyPort), authID_(authID), authPassword_(authPassword),  httpTrafficFilter_(httpTrafficFilter) {
}

std::shared_ptr<Connection> HTTPConnectProxiedConnectionFactory::createConnection() {
    HTTPConnectProxiedConnection::ref proxyConnection = HTTPConnectProxiedConnection::create(resolver_, connectionFactory_, timerFactory_, proxyHost_, proxyPort_, authID_, authPassword_);
    proxyConnection->setHTTPTrafficFilter(httpTrafficFilter_);
    return proxyConnection;
}

}
