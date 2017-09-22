#ifndef JXMPP_DUMMYCONNECTIONFACTORY_H
#define JXMPP_DUMMYCONNECTIONFACTORY_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Network/ConnectionFactory.h>
#include <JXMPP/Network/DummyConnection.h>

namespace JXMPP {

class EventLoop;

class DummyConnectionFactory : public ConnectionFactory {
public:
    DummyConnectionFactory(EventLoop *eventLoop) : eventLoop(eventLoop) {}
    virtual ~DummyConnectionFactory() {}
    virtual std::shared_ptr<Connection> createConnection() {
        return std::make_shared<DummyConnection>(eventLoop);
    }
private:
    EventLoop* eventLoop;
};

}

#endif // JXMPP_DUMMYCONNECTIONFACTORY_H
