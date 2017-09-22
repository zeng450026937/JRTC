#include <JXMPP/EventLoop/BoostASIOEventLoop.h>

#include <boost/bind.hpp>

namespace JXMPP {

BoostASIOEventLoop::BoostASIOEventLoop(std::shared_ptr<boost::asio::io_service> ioService) : ioService_(ioService) {

}

BoostASIOEventLoop::~BoostASIOEventLoop() {

}

void BoostASIOEventLoop::handleASIOEvent() {
    {
        std::unique_lock<std::recursive_mutex> lock(isEventInASIOEventLoopMutex_);
        isEventInASIOEventLoop_ = false;
    }
    handleNextEvents();
}

void BoostASIOEventLoop::eventPosted() {
    std::unique_lock<std::recursive_mutex> lock(isEventInASIOEventLoopMutex_);
    if (!isEventInASIOEventLoop_) {
        isEventInASIOEventLoop_ = true;
        ioService_->post(boost::bind(&BoostASIOEventLoop::handleASIOEvent, this));
    }
}

}
