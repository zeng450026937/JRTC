#ifndef JXMPP_CONNECTIONSERVERFACTORY_H
#define JXMPP_CONNECTIONSERVERFACTORY_H

/*
 * Copyright (c) 2011 Jan Kaluza
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class ConnectionServer;
    class HostAddress;

    class JXMPP_API ConnectionServerFactory {
        public:
            virtual ~ConnectionServerFactory();

            virtual std::shared_ptr<ConnectionServer> createConnectionServer(int port) = 0;

            virtual std::shared_ptr<ConnectionServer> createConnectionServer(const JXMPP::HostAddress& hostAddress, int port) = 0;
    };
}

#endif // JXMPP_CONNECTIONSERVERFACTORY_H
