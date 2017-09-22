#ifndef JXMPP_PROXYPROVIDER_H
#define JXMPP_PROXYPROVIDER_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <map>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/String.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class JXMPP_API ProxyProvider {
        public:
            ProxyProvider();
            virtual ~ProxyProvider();
            virtual HostAddressPort getHTTPConnectProxy() const = 0;
            virtual HostAddressPort getSOCKS5Proxy() const = 0;
    };
}

#endif // JXMPP_PROXYPROVIDER_H
