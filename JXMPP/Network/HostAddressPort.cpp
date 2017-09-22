#include <JXMPP/Network/HostAddressPort.h>

#include <boost/lexical_cast.hpp>

using namespace JXMPP;

HostAddressPort::HostAddressPort(const HostAddress& address, int port) : address_(address), port_(port) {
}

HostAddressPort::HostAddressPort(const boost::asio::ip::tcp::endpoint& endpoint) {
    address_ = HostAddress(endpoint.address());
    port_ = endpoint.port();
}

std::string HostAddressPort::toString() const {
    std::string portAsString;
    try {
        portAsString = boost::lexical_cast<std::string>(getPort());
    } catch (boost::bad_lexical_cast&) {
    }
    return getAddress().toString() + ":" + portAsString;
}
