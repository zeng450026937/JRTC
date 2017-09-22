#ifndef JXMPP_SOLARISNETWORKENVIRONMENT_H
#define JXMPP_SOLARISNETWORKENVIRONMENT_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Network/NetworkEnvironment.h>
#include <JXMPP/Network/NetworkInterface.h>

namespace JXMPP {

    class SolarisNetworkEnvironment : public NetworkEnvironment {
        public:
            std::vector<NetworkInterface> getNetworkInterfaces() const;
    };

}

#endif // JXMPP_SOLARISNETWORKENVIRONMENT_H
