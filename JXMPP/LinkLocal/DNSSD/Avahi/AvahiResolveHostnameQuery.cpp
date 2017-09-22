#include <JXMPP/LinkLocal/DNSSD/Avahi/AvahiResolveHostnameQuery.h>

#include <boost/bind.hpp>

#include <netinet/in.h>

#include <JXMPP/Base/Log.h>

namespace JXMPP {

AvahiResolveHostnameQuery::AvahiResolveHostnameQuery(const std::string& hostname, int, std::shared_ptr<AvahiQuerier> querier, EventLoop* eventLoop) : AvahiQuery(querier, eventLoop), hostname(hostname) {
    JXMPP_LOG(debug) << "Resolving hostname " << hostname << std::endl;
}

void AvahiResolveHostnameQuery::run() {
        eventLoop->postEvent(boost::bind(boost::ref(onHostnameResolved), HostAddress::fromString(hostname)), shared_from_this());
}

}
