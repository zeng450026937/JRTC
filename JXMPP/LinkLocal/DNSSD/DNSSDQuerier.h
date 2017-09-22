#ifndef JXMPP_DNSSDQUERIER_H
#define JXMPP_DNSSDQUERIER_H

#include <memory>

#include <JXMPP/Base/ByteArray.h>

namespace JXMPP {
    class DNSSDServiceID;
    class DNSSDBrowseQuery;
    class DNSSDRegisterQuery;
    class DNSSDResolveServiceQuery;
    class DNSSDResolveHostnameQuery;

    class DNSSDQuerier {
        public:
            virtual ~DNSSDQuerier();

            virtual void start() = 0;
            virtual void stop() = 0;

            virtual std::shared_ptr<DNSSDBrowseQuery> createBrowseQuery() = 0;
            virtual std::shared_ptr<DNSSDRegisterQuery> createRegisterQuery(
                    const std::string& name, int port, const ByteArray& info) = 0;
            virtual std::shared_ptr<DNSSDResolveServiceQuery> createResolveServiceQuery(
                    const DNSSDServiceID&) = 0;
            virtual std::shared_ptr<DNSSDResolveHostnameQuery> createResolveHostnameQuery(
                    const std::string& hostname, int interfaceIndex) = 0;
    };
}

#endif // JXMPP_DNSSDQUERIER_H
