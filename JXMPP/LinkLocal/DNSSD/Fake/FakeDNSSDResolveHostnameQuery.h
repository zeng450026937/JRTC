#ifndef JXMPP_FAKEDNSSDRESOLVEHOSTNAMEQUERY_H
#define JXMPP_FAKEDNSSDRESOLVEHOSTNAMEQUERY_H

#include <string>

#include <JXMPP/LinkLocal/DNSSD/DNSSDResolveHostnameQuery.h>
#include <JXMPP/LinkLocal/DNSSD/Fake/FakeDNSSDQuery.h>
#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class FakeDNSSDQuerier;

    class FakeDNSSDResolveHostnameQuery : public DNSSDResolveHostnameQuery, public FakeDNSSDQuery {
        public:
            FakeDNSSDResolveHostnameQuery(const std::string& hostname, int interfaceIndex, std::shared_ptr<FakeDNSSDQuerier> querier) : FakeDNSSDQuery(querier), hostname(hostname), interfaceIndex(interfaceIndex) {
            }

            void run() {
                FakeDNSSDQuery::run();
            }

            void finish() {
                FakeDNSSDQuery::finish();
            }

            std::string hostname;
            int interfaceIndex;
    };
}

#endif // JXMPP_FAKEDNSSDRESOLVEHOSTNAMEQUERY_H
