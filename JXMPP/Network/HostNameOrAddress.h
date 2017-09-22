#ifndef JXMPP_HOSTNAMEORADDRESS_H
#define JXMPP_HOSTNAMEORADDRESS_H

#include <string>

#include <boost/variant.hpp>

#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    typedef boost::variant<std::string, HostAddress> HostNameOrAddress;

    std::string toString(const HostNameOrAddress& address);
}

#endif // JXMPP_HOSTNAMEORADDRESS_H
