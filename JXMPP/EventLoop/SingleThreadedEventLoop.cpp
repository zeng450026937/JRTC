/*
 * Copyright (c) 2010 Soren Dreijer
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/EventLoop/SingleThreadedEventLoop.h>

#include <iostream>

#include <boost/bind.hpp>

namespace JXMPP {

SingleThreadedEventLoop::SingleThreadedEventLoop()
: shouldShutDown_(false), eventAvailable_(false)
{
}

SingleThreadedEventLoop::~SingleThreadedEventLoop() {

}

void SingleThreadedEventLoop::waitForEvents() {
    std::unique_lock<std::mutex> lock(eventAvailableMutex_);
    while (!eventAvailable_ && !shouldShutDown_) {
        eventAvailableCondition_.wait(lock);
    }

    if (shouldShutDown_) {
        throw EventLoopCanceledException();
    }
}

void SingleThreadedEventLoop::handleEvents() {
    {
        std::lock_guard<std::mutex> lock(eventAvailableMutex_);
        eventAvailable_ = false;
    }
    handleNextEvents();
}

void SingleThreadedEventLoop::stop() {
    std::unique_lock<std::mutex> lock(eventAvailableMutex_);
    shouldShutDown_ = true;
    eventAvailableCondition_.notify_one();
}

void SingleThreadedEventLoop::eventPosted() {
    std::lock_guard<std::mutex> lock(eventAvailableMutex_);
    eventAvailable_ = true;
    eventAvailableCondition_.notify_one();
}

} // namespace JXMPP
