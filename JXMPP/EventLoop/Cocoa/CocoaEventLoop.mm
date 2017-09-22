#include <JXMPP/EventLoop/Cocoa/CocoaEventLoop.h>
#include <JXMPP/EventLoop/Cocoa/CocoaEvent.h>

#pragma GCC diagnostic ignored "-Wold-style-cast"

namespace JXMPP {

CocoaEventLoop::CocoaEventLoop() : isEventInCocoaEventLoop_(false) {
}

CocoaEventLoop::~CocoaEventLoop() {

}

void CocoaEventLoop::handleNextCocoaEvent() {
    {
        std::unique_lock<std::recursive_mutex> lock(isEventInCocoaEventLoopMutex_);
        isEventInCocoaEventLoop_ = false;
    }
    handleNextEvents();
}

void CocoaEventLoop::eventPosted() {
    std::unique_lock<std::recursive_mutex> lock(isEventInCocoaEventLoopMutex_);
    if (!isEventInCocoaEventLoop_) {
        isEventInCocoaEventLoop_ = true;

        CocoaEvent* cocoaEvent = [[CocoaEvent alloc] init: this];
        [cocoaEvent
            performSelectorOnMainThread:@selector(process)
            withObject: nil
            waitUntilDone: NO];
        [cocoaEvent release];
    }
}

}
