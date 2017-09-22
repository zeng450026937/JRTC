#include <JXMPP/Network/BoostTimerFactory.h>

#include <JXMPP/Network/BoostTimer.h>

namespace JXMPP {

BoostTimerFactory::BoostTimerFactory(std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop) : ioService(ioService), eventLoop(eventLoop) {
}

std::shared_ptr<Timer> BoostTimerFactory::createTimer(int milliseconds) {
    return BoostTimer::create(milliseconds, ioService, eventLoop);
}

}
