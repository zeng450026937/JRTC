#ifndef JXMPP_NATTRAVERSALREMOVEPORTFORWARDINGREQUEST_H
#define JXMPP_NATTRAVERSALREMOVEPORTFORWARDINGREQUEST_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class JXMPP_API NATTraversalRemovePortForwardingRequest {
        public:
            struct PortMapping {
                enum Protocol {
                    TCP,
                    UDP
                };

                unsigned int publicPort;
                unsigned int localPort;
                Protocol protocol;
                unsigned long leaseInSeconds;
            };

        public:
            virtual ~NATTraversalRemovePortForwardingRequest();

            virtual void start() = 0;
            virtual void stop() = 0;

            boost::signals2::signal<void (boost::optional<bool> /* failure */)> onResult;
    };
}

#endif // JXMPP_NATTRAVERSALREMOVEPORTFORWARDINGREQUEST_H
