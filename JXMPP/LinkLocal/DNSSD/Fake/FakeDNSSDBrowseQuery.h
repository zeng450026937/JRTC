#ifndef JXMPP_FAKEDNSSDBROWSEQUERY_H
#define JXMPP_FAKEDNSSDBROWSEQUERY_H

#include <JXMPP/LinkLocal/DNSSD/DNSSDBrowseQuery.h>
#include <JXMPP/LinkLocal/DNSSD/Fake/FakeDNSSDQuery.h>

namespace JXMPP {
    class FakeDNSSDQuerier;

    class FakeDNSSDBrowseQuery : public DNSSDBrowseQuery, public FakeDNSSDQuery {
        public:
            FakeDNSSDBrowseQuery(std::shared_ptr<FakeDNSSDQuerier> querier) : FakeDNSSDQuery(querier) {
            }

            void startBrowsing() {
                run();
            }

            void stopBrowsing() {
                finish();
            }
    };
}

#endif // JXMPP_FAKEDNSSDBROWSEQUERY_H
