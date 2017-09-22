#include <JXMPP/LinkLocal/DNSSD/Avahi/AvahiQuery.h>

#include <JXMPP/LinkLocal/DNSSD/Avahi/AvahiQuerier.h>

namespace JXMPP {

AvahiQuery::AvahiQuery(std::shared_ptr<AvahiQuerier> q, EventLoop* eventLoop) : querier(q), eventLoop(eventLoop) {
}

AvahiQuery::~AvahiQuery() {
}

}
