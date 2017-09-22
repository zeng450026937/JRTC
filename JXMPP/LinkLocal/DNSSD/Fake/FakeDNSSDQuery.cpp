#include <JXMPP/LinkLocal/DNSSD/Fake/FakeDNSSDQuery.h>

#include <JXMPP/LinkLocal/DNSSD/Fake/FakeDNSSDQuerier.h>

namespace JXMPP {

FakeDNSSDQuery::FakeDNSSDQuery(std::shared_ptr<FakeDNSSDQuerier> querier) : querier(querier) {
}

FakeDNSSDQuery::~FakeDNSSDQuery() {
}

void FakeDNSSDQuery::run() {
    querier->addRunningQuery(shared_from_this());
}

void FakeDNSSDQuery::finish() {
    querier->removeRunningQuery(shared_from_this());
}

}
