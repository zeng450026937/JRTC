#ifndef JXMPP_WINDOWSNETWORKENVIRONMENT_H
#define JXMPP_WINDOWSNETWORKENVIRONMENT_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/NetworkEnvironment.h>

namespace JXMPP {
    class JXMPP_API WindowsNetworkEnvironment : public NetworkEnvironment {
        public:
            std::vector<NetworkInterface> getNetworkInterfaces() const;
    };
}

#endif // JXMPP_WINDOWSNETWORKENVIRONMENT_H
