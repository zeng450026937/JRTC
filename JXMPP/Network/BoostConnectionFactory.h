#ifndef JXMPP_BOOSTCONNECTIONFACTORY_H
#define JXMPP_BOOSTCONNECTIONFACTORY_H

#include <boost/asio/io_service.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/BoostConnection.h>
#include <JXMPP/Network/ConnectionFactory.h>

namespace JXMPP {
    class JXMPP_API BoostConnectionFactory : public ConnectionFactory {
        public:
            BoostConnectionFactory(std::shared_ptr<boost::asio::io_service>, EventLoop* eventLoop);

            virtual std::shared_ptr<Connection> createConnection();

        private:
            std::shared_ptr<boost::asio::io_service> ioService;
            EventLoop* eventLoop;
    };
}

#endif // JXMPP_BOOSTCONNECTIONFACTORY_H
