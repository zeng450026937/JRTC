#ifndef JXMPP_AVAHIRESOLVEHOSTNAMEQUERY_H
#define JXMPP_AVAHIRESOLVEHOSTNAMEQUERY_H

#include <string>

#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/LinkLocal/DNSSD/Avahi/AvahiQuery.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDResolveHostnameQuery.h>
#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class AvahiQuerier;

    class AvahiResolveHostnameQuery : public DNSSDResolveHostnameQuery, public AvahiQuery {
        public:
            AvahiResolveHostnameQuery(const std::string& hostname, int, std::shared_ptr<AvahiQuerier> querier, EventLoop* eventLoop);

            void run();

            void finish() {
            }

        private:
            HostAddress hostAddress;
            std::string hostname;
    };
}

#endif // JXMPP_AVAHIRESOLVEHOSTNAMEQUERY_H
