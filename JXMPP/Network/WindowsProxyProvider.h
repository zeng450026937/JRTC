#ifndef JXMPP_WINDOWSPROXYPROVIDER_H
#define JXMPP_WINDOWSPROXYPROVIDER_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Network/HostAddressPort.h>
#include <JXMPP/Network/ProxyProvider.h>

namespace JXMPP {
    class JXMPP_API WindowsProxyProvider : public ProxyProvider {
        public:
            WindowsProxyProvider();
            virtual HostAddressPort getHTTPConnectProxy() const;
            virtual HostAddressPort getSOCKS5Proxy() const;
        private:
            HostAddressPort getAsHostAddressPort(std::string proxy);
            bool proxyEnabled(HKEY hKey) const;
            HostAddressPort socksProxy;
            HostAddressPort httpProxy;
    };
}

#endif // JXMPP_WINDOWSPROXYPROVIDER_H
