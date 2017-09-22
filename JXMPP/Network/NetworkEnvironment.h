#ifndef JXMPP_NETWORKENVIRONMENT_H
#define JXMPP_NETWORKENVIRONMENT_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/NetworkInterface.h>

namespace JXMPP {
    class JXMPP_API NetworkEnvironment {
    public:
        virtual ~NetworkEnvironment();

        virtual std::vector<NetworkInterface> getNetworkInterfaces() const = 0;

        HostAddress getLocalAddress() const;
    };
}

#endif // JXMPP_NETWORKENVIRONMENT_H
