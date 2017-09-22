#include <JXMPP/Network/HostNameOrAddress.h>

using namespace JXMPP;

namespace {
    struct ToStringVisitor : public boost::static_visitor<std::string> {
            std::string operator()(const HostAddress& address) const {
                return address.toString();
            }

            std::string operator()(const std::string & str) const {
                return str;
            }
    };
}

namespace JXMPP {

std::string toString(const HostNameOrAddress& address) {
    return boost::apply_visitor(ToStringVisitor(), address);
}

}
