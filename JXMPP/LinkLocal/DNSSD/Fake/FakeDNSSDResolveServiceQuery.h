#ifndef JXMPP_FAKEDNSSDRESOLVESERVICEQUERY_H
#define JXMPP_FAKEDNSSDRESOLVESERVICEQUERY_H

#include <JXMPP/LinkLocal/DNSSD/DNSSDResolveServiceQuery.h>
#include <JXMPP/LinkLocal/DNSSD/Fake/FakeDNSSDQuery.h>
#include <JXMPP/LinkLocal/LinkLocalServiceInfo.h>

namespace JXMPP {
    class FakeDNSSDQuerier;

    class FakeDNSSDResolveServiceQuery : public DNSSDResolveServiceQuery, public FakeDNSSDQuery {
        public:
            FakeDNSSDResolveServiceQuery(const DNSSDServiceID& service, std::shared_ptr<FakeDNSSDQuerier> querier) : FakeDNSSDQuery(querier), service(service) {
            }

            void start() {
                run();
            }

            void stop() {
                finish();
            }

            DNSSDServiceID service;
    };
}

#endif // JXMPP_FAKEDNSSDRESOLVESERVICEQUERY_H
