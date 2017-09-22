#ifndef JXMPP_NETWORKINTERFACE_H
#define JXMPP_NETWORKINTERFACE_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class JXMPP_API NetworkInterface {
        public:
            NetworkInterface(const std::string& name, bool loopback) : name(name), loopback(loopback) {
            }

            void addAddress(const HostAddress& address) {
                addresses.push_back(address);
            }

            const std::vector<HostAddress>& getAddresses() const {
                return addresses;
            }

            const std::string& getName() const {
                return name;
            }

            bool isLoopback() const {
                return loopback;
            }

        private:
            std::string name;
            bool loopback;
            std::vector<HostAddress> addresses;
    };
}

#endif // JXMPP_NETWORKINTERFACE_H
