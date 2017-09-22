#ifndef JXMPP_ENVIRONMENTPROXYPROVIDER_H
#define JXMPP_ENVIRONMENTPROXYPROVIDER_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Network/ProxyProvider.h>

namespace JXMPP {
    class JXMPP_API EnvironmentProxyProvider : public ProxyProvider {
        public:
            EnvironmentProxyProvider();
            virtual HostAddressPort getHTTPConnectProxy() const;
            virtual HostAddressPort getSOCKS5Proxy() const;
        private:
            HostAddressPort getFromEnv(const char* envVarName, std::string proxyProtocol);
            HostAddressPort socksProxy;
            HostAddressPort httpProxy;
    };
}

#endif // JXMPP_ENVIRONMENTPROXYPROVIDER_H
