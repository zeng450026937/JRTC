#include <JXMPP/Network/DummyConnection.h>

#include <cassert>
#include <memory>

#include <boost/bind.hpp>

namespace JXMPP {

DummyConnection::DummyConnection(EventLoop* eventLoop) : eventLoop(eventLoop) {
}

void DummyConnection::receive(const SafeByteArray& data) {
    eventLoop->postEvent(boost::bind(boost::ref(onDataRead), std::make_shared<SafeByteArray>(data)), shared_from_this());
}

void DummyConnection::listen() {
    assert(false);
}

void DummyConnection::connect(const HostAddressPort&) {
    assert(false);
}


}
