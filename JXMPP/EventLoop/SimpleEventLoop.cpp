#include <JXMPP/EventLoop/SimpleEventLoop.h>

#include <boost/bind.hpp>

namespace JXMPP {

SimpleEventLoop::SimpleEventLoop() : isRunning_(true), eventAvailable_(false) {
}

SimpleEventLoop::~SimpleEventLoop() {
}

void SimpleEventLoop::doRun(bool breakAfterEvents) {
    while (isRunning_) {
        {
            std::unique_lock<std::mutex> lock(eventAvailableMutex_);
            while (!eventAvailable_) {
                eventAvailableCondition_.wait(lock);
            }

            eventAvailable_ = false;
        }
        runOnce();
        if (breakAfterEvents) {
            return;
        }
    }
}

void SimpleEventLoop::runOnce() {
    handleNextEvents();
}

void SimpleEventLoop::stop() {
    postEvent(boost::bind(&SimpleEventLoop::doStop, this));
}

void SimpleEventLoop::doStop() {
    isRunning_ = false;
}

void SimpleEventLoop::eventPosted() {
    {
        std::unique_lock<std::mutex> lock(eventAvailableMutex_);
        eventAvailable_ = true;
    }
    eventAvailableCondition_.notify_one();
}


}
