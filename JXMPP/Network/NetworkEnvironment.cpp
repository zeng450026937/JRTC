#include <JXMPP/Network/NetworkEnvironment.h>

#include <JXMPP/Network/HostAddress.h>
#include <JXMPP/Network/NetworkInterface.h>

namespace JXMPP {

NetworkEnvironment::~NetworkEnvironment() {
}

HostAddress NetworkEnvironment::getLocalAddress() const {
    std::vector<NetworkInterface> networkInterfaces = getNetworkInterfaces();
    for (const auto& iface : networkInterfaces) {
        if (!iface.isLoopback()) {
            for (const auto& address : iface.getAddresses()) {
                if (address.getRawAddress().is_v4()) {
                    return address;
                }
            }
        }
    }
    return HostAddress();
}

}
