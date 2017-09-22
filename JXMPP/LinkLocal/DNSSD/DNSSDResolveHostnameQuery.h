#ifndef JXMPP_DNSSDRESOLVEHOSTNAMEQUERY_H
#define JXMPP_DNSSDRESOLVEHOSTNAMEQUERY_H

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class DNSSDResolveHostnameQuery {
        public:
            virtual ~DNSSDResolveHostnameQuery();

            virtual void run() = 0;
            virtual void finish() = 0;

            boost::signals2::signal<void (const boost::optional<HostAddress>&)> onHostnameResolved;
    };
}

#endif // JXMPP_DNSSDRESOLVEHOSTNAMEQUERY_H
