#ifndef JXMPP_MACOSXPROXYPROVIDER_H
#define JXMPP_MACOSXPROXYPROVIDER_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <CoreFoundation/CoreFoundation.h>

#include <JXMPP/Network/ProxyProvider.h>

namespace JXMPP {
    class MacOSXProxyProvider : public ProxyProvider {
        public:
            MacOSXProxyProvider();
            virtual HostAddressPort getHTTPConnectProxy() const;
            virtual HostAddressPort getSOCKS5Proxy() const;
    };
}

#endif // JXMPP_MACOSXPROXYPROVIDER_H
