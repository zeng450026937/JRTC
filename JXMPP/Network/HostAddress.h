#ifndef JXMPP_HOSTADDRESS_H
#define JXMPP_HOSTADDRESS_H

#include <string>

#include <boost/asio/ip/address.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API HostAddress {
        public:
            HostAddress();
            HostAddress(const unsigned char* address, size_t length);
            HostAddress(const boost::asio::ip::address& address);

            std::string toString() const;
            boost::asio::ip::address getRawAddress() const;

            bool operator==(const HostAddress& o) const {
                return address_ == o.address_;
            }

            bool isValid() const;
            bool isLocalhost() const;

            static boost::optional<HostAddress> fromString(const std::string& addressString);

        private:
            boost::asio::ip::address address_;
    };
}

#endif // JXMPP_HOSTADDRESS_H
