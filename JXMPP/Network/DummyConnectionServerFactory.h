#ifndef JXMPP_DUMMYCONNECTIONSERVERFACTORY_H
#define JXMPP_DUMMYCONNECTIONSERVERFACTORY_H

#include <memory>

#include <JXMPP/Network/ConnectionServerFactory.h>
#include <JXMPP/Network/DummyConnectionServer.h>

namespace JXMPP {

class EventLoop;

class DummyConnectionServerFactory : public ConnectionServerFactory {
public:
    DummyConnectionServerFactory(EventLoop* eventLoop) : eventLoop(eventLoop) {}
    virtual ~DummyConnectionServerFactory() {}

    virtual std::shared_ptr<ConnectionServer> createConnectionServer(int port) {
        return std::make_shared<DummyConnectionServer>(eventLoop, port);
    }

    virtual std::shared_ptr<ConnectionServer> createConnectionServer(const JXMPP::HostAddress& hostAddress, int port) {
        return std::make_shared<DummyConnectionServer>(eventLoop, hostAddress, port);
    }

private:
    EventLoop* eventLoop;
};

}

#endif // JXMPP_DUMMYCONNECTIONSERVERFACTORY_H
