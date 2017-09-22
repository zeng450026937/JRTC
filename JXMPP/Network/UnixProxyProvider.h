#ifndef JXMPP_UNIXPROXYPROVIDER_H
#define JXMPP_UNIXPROXYPROVIDER_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Network/EnvironmentProxyProvider.h>

namespace JXMPP {
    class GConfProxyProvider;

    class UnixProxyProvider : public ProxyProvider {
        public:
            UnixProxyProvider();
            virtual ~UnixProxyProvider();

            virtual HostAddressPort getHTTPConnectProxy() const;
            virtual HostAddressPort getSOCKS5Proxy() const;

        private:
            GConfProxyProvider* gconfProxyProvider;
            EnvironmentProxyProvider environmentProxyProvider;
    };
}

#endif // JXMPP_UNIXPROXYPROVIDER_H
