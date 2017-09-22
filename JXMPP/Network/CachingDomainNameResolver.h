#ifndef JXMPP_CACHINGDOMAINNAMERESOLVER_H
#define JXMPP_CACHINGDOMAINNAMERESOLVER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/DomainNameResolver.h>
#include <JXMPP/Network/StaticDomainNameResolver.h>

/*
 * FIXME: Does not do any caching yet.
 */
namespace JXMPP {
    class EventLoop;

    class JXMPP_API CachingDomainNameResolver : public DomainNameResolver {
        public:
            CachingDomainNameResolver(DomainNameResolver* realResolver, EventLoop* eventLoop);
            ~CachingDomainNameResolver();

            virtual DomainNameServiceQuery::ref createServiceQuery(const std::string& serviceLookupPrefix, const std::string& domain);
            virtual DomainNameAddressQuery::ref createAddressQuery(const std::string& name);

        private:
            DomainNameResolver* realResolver;
    };
}

#endif // JXMPP_CACHINGDOMAINNAMERESOLVER_H
