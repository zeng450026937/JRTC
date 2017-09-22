#ifndef JXMPP_FAKEDNSSDREGISTERQUERY_H
#define JXMPP_FAKEDNSSDREGISTERQUERY_H

#include <string>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDRegisterQuery.h>
#include <JXMPP/LinkLocal/DNSSD/Fake/FakeDNSSDQuery.h>

namespace JXMPP {
    class FakeDNSSDQuerier;

    class FakeDNSSDRegisterQuery : public DNSSDRegisterQuery, public FakeDNSSDQuery {
        public:
            FakeDNSSDRegisterQuery(const std::string& name, int port, const ByteArray& info, std::shared_ptr<FakeDNSSDQuerier> querier) : FakeDNSSDQuery(querier), name(name), port(port), info(info) {
            }

            void registerService() {
                run();
            }

            void updateServiceInfo(const ByteArray& i) {
                info = i;
            }

            void unregisterService() {
                finish();
            }

            std::string name;
            int port;
            ByteArray info;
    };
}

#endif // JXMPP_FAKEDNSSDREGISTERQUERY_H
