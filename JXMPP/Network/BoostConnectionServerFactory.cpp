/*
 * Copyright (c) 2011 Jan Kaluza
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Network/BoostConnectionServerFactory.h>

#include <JXMPP/Network/BoostConnectionServer.h>

namespace JXMPP {

BoostConnectionServerFactory::BoostConnectionServerFactory(std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop) : ioService(ioService), eventLoop(eventLoop) {
}

std::shared_ptr<ConnectionServer> BoostConnectionServerFactory::createConnectionServer(int port) {
    return BoostConnectionServer::create(port, ioService, eventLoop);
}

std::shared_ptr<ConnectionServer> BoostConnectionServerFactory::createConnectionServer(const JXMPP::HostAddress &hostAddress, int port) {
    return BoostConnectionServer::create(hostAddress, port, ioService, eventLoop);
}

}
