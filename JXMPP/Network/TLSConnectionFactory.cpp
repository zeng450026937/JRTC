#include <JXMPP/Network/TLSConnectionFactory.h>

#include <memory>

#include <JXMPP/Network/TLSConnection.h>

namespace JXMPP {

TLSConnectionFactory::TLSConnectionFactory(TLSContextFactory* contextFactory, ConnectionFactory* connectionFactory, const TLSOptions& o) : contextFactory(contextFactory), connectionFactory(connectionFactory), options_(o) {

}

TLSConnectionFactory::~TLSConnectionFactory() {

}


std::shared_ptr<Connection> TLSConnectionFactory::createConnection() {
    return std::make_shared<TLSConnection>(connectionFactory->createConnection(), contextFactory, options_);
}

}
