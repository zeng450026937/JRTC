#ifndef JXMPP_TLSCONNECTIONFACTORY_H
#define JXMPP_TLSCONNECTIONFACTORY_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/ConnectionFactory.h>
#include <JXMPP/TLS/TLSContextFactory.h>
#include <JXMPP/TLS/TLSOptions.h>

namespace JXMPP {
    class Connection;

    class JXMPP_API TLSConnectionFactory : public ConnectionFactory {
        public:
            TLSConnectionFactory(TLSContextFactory* contextFactory, ConnectionFactory* connectionFactory, const TLSOptions&);
            virtual ~TLSConnectionFactory();

            virtual std::shared_ptr<Connection> createConnection();
        private:
            TLSContextFactory* contextFactory;
            ConnectionFactory* connectionFactory;
            TLSOptions options_;
    };
}

#endif // JXMPP_TLSCONNECTIONFACTORY_H
