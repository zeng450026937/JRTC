#ifndef JXMPP_BOOSTCONNECTIONSERVERFACTORY_H
#define JXMPP_BOOSTCONNECTIONSERVERFACTORY_H

/*
 * Copyright (c) 2011 Jan Kaluza
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <boost/asio/io_service.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/BoostConnectionServer.h>
#include <JXMPP/Network/ConnectionServerFactory.h>

namespace JXMPP {
    class ConnectionServer;

    class JXMPP_API BoostConnectionServerFactory : public ConnectionServerFactory {
        public:
            BoostConnectionServerFactory(std::shared_ptr<boost::asio::io_service>, EventLoop* eventLoop);

            virtual std::shared_ptr<ConnectionServer> createConnectionServer(int port);

            virtual std::shared_ptr<ConnectionServer> createConnectionServer(const JXMPP::HostAddress &hostAddress, int port);

        private:
            std::shared_ptr<boost::asio::io_service> ioService;
            EventLoop* eventLoop;
    };
}

#endif // JXMPP_BOOSTCONNECTIONSERVERFACTORY_H
