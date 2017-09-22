#ifndef JXMPP_NATPORTMAPPING_H
#define JXMPP_NATPORTMAPPING_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class JXMPP_API NATPortMapping {
    public:
        enum Protocol {
            TCP,
            UDP
        };

        NATPortMapping(int localPort, int publicPort, Protocol protocol = TCP, int leaseInSeconds = 60 * 60 * 24) :
            publicPort(publicPort), localPort(localPort), protocol(protocol), leaseInSeconds(leaseInSeconds) {

        }

        int getPublicPort() const {
            return publicPort;
        }

        int getLocalPort() const {
            return localPort;
        }

        Protocol getProtocol() const {
            return protocol;
        }

        int getLeaseInSeconds() const {
            return leaseInSeconds;
        }

    private:
        int publicPort;
        int localPort;
        Protocol protocol;
        int leaseInSeconds;
    };
}

#endif // JXMPP_NATPORTMAPPING_H
