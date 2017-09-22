#ifndef JXMPP_DNSSDBROWSEQUERY_H
#define JXMPP_DNSSDBROWSEQUERY_H

#include <boost/signals2.hpp>

#include <JXMPP/LinkLocal/DNSSD/DNSSDServiceID.h>

namespace JXMPP {
    class DNSSDBrowseQuery {
        public:
            virtual ~DNSSDBrowseQuery();

            virtual void startBrowsing() = 0;
            virtual void stopBrowsing() = 0;

            boost::signals2::signal<void (const DNSSDServiceID&)> onServiceAdded;
            boost::signals2::signal<void (const DNSSDServiceID&)> onServiceRemoved;
            boost::signals2::signal<void ()> onError;
    };
}

#endif // JXMPP_DNSSDBROWSEQUERY_H
