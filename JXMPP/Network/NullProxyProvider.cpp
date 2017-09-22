#include <JXMPP/Network/NullProxyProvider.h>

using namespace JXMPP;

NullProxyProvider::NullProxyProvider() {
}

HostAddressPort NullProxyProvider::getHTTPConnectProxy() const {
    return HostAddressPort();
}

HostAddressPort NullProxyProvider::getSOCKS5Proxy() const {
    return HostAddressPort();
}
