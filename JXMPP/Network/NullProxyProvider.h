#ifndef JXMPP_NULLPROXYPROVIDER_H
#define JXMPP_NULLPROXYPROVIDER_H

#include <JXMPP/Network/ProxyProvider.h>

namespace JXMPP {
    class NullProxyProvider : public ProxyProvider {
        public:
            NullProxyProvider();

            virtual HostAddressPort getHTTPConnectProxy() const;
            virtual HostAddressPort getSOCKS5Proxy() const;
    };
}

#endif // JXMPP_NULLPROXYPROVIDER_H
