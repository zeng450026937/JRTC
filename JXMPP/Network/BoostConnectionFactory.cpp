#include <JXMPP/Network/BoostConnectionFactory.h>

#include <JXMPP/Network/BoostConnection.h>

namespace JXMPP {

BoostConnectionFactory::BoostConnectionFactory(std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop) : ioService(ioService), eventLoop(eventLoop) {
}

std::shared_ptr<Connection> BoostConnectionFactory::createConnection() {
    return BoostConnection::create(ioService, eventLoop);
}

}
