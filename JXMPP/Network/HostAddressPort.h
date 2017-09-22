#ifndef JXMPP_HOSTADDRESSPORT_H
#define JXMPP_HOSTADDRESSPORT_H

#include <boost/asio/ip/tcp.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class JXMPP_API HostAddressPort {
        public:
            HostAddressPort(const HostAddress& address = HostAddress(), int port = -1);
            HostAddressPort(const boost::asio::ip::tcp::endpoint& endpoint);

            const HostAddress& getAddress() const {
                return address_;
            }

            int getPort() const {
                return port_;
            }

            bool operator==(const HostAddressPort& o) const {
                return address_ == o.address_ && port_ == o.port_;
            }

            bool isValid() const {
                return address_.isValid() && port_ > 0;
            }

            std::string toString() const;

        private:
            HostAddress address_;
            int port_;
    };
}

#endif // JXMPP_HOSTADDRESSPORT_H
