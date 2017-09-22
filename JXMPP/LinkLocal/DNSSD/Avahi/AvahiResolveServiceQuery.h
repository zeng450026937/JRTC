#ifndef JXMPP_AVAHIRESOLVESERVICEQUERY_H
#define JXMPP_AVAHIRESOLVESERVICEQUERY_H

#include <avahi-client/lookup.h>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/LinkLocal/DNSSD/Avahi/AvahiQuery.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDResolveServiceQuery.h>
#include <JXMPP/LinkLocal/LinkLocalServiceInfo.h>

namespace JXMPP {
    class AvahiQuerier;

    class AvahiResolveServiceQuery : public DNSSDResolveServiceQuery, public AvahiQuery {
        public:
            AvahiResolveServiceQuery(const DNSSDServiceID& service, std::shared_ptr<AvahiQuerier> querier, EventLoop* eventLoop) : AvahiQuery(querier, eventLoop), service(service), resolver(NULL) {
            }

            void start();
            void stop();

        private:
            static void handleServiceResolvedStatic(AvahiServiceResolver* resolver, AvahiIfIndex interfaceIndex, AvahiProtocol protocol, AvahiResolverEvent event, const char *name, const char *type, const char *domain, const char *host_name, const AvahiAddress *address, uint16_t port, AvahiStringList *txt, AvahiLookupResultFlags flags, void* context) {
                static_cast<AvahiResolveServiceQuery*>(context)->handleServiceResolved(resolver, interfaceIndex, protocol, event, name, type, domain, host_name, address, port, txt, flags);
            }

            void handleServiceResolved(AvahiServiceResolver* resolver, AvahiIfIndex, AvahiProtocol, AvahiResolverEvent event, const char *name, const char * type, const char* domain, const char * /*host_name*/, const AvahiAddress *address, uint16_t port, AvahiStringList *txt, AvahiLookupResultFlags);

        private:
            DNSSDServiceID service;
            AvahiServiceResolver* resolver;
    };
}

#endif // JXMPP_AVAHIRESOLVESERVICEQUERY_H
