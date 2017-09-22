#include <JXMPP/EventLoop/DummyEventLoop.h>

#include <JXMPP/Base/Log.h>

namespace JXMPP {

DummyEventLoop::DummyEventLoop() {
}

DummyEventLoop::~DummyEventLoop() {
    if (hasEvents()) {
        JXMPP_LOG(warning) << "DummyEventLoop: Unhandled events at destruction time" << std::endl;
    }
}

void DummyEventLoop::processEvents() {
    while(hasEvents()) {
        hasEvents_ = false;
        handleNextEvents();
    }
}

bool DummyEventLoop::hasEvents() {
    return hasEvents_;
}

void DummyEventLoop::eventPosted() {
    hasEvents_ = true;
}

}
