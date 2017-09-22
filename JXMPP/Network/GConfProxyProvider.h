#ifndef JXMPP_GCONFPROXYPROVIDER_H
#define JXMPP_GCONFPROXYPROVIDER_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Network/ProxyProvider.h>

namespace JXMPP {
    class GConfProxyProvider : public ProxyProvider {
        public:
            GConfProxyProvider();
            virtual HostAddressPort getHTTPConnectProxy() const;
            virtual HostAddressPort getSOCKS5Proxy() const;
        private:
            HostAddressPort getFromGConf(const char* gcHost, const char* gcPort);
            HostAddressPort socksProxy;
            HostAddressPort httpProxy;
    };
}

#endif // JXMPP_GCONFPROXYPROVIDER_H
