#include <JXMPP/Network/CachingDomainNameResolver.h>

#include <memory>

namespace JXMPP {

CachingDomainNameResolver::CachingDomainNameResolver(DomainNameResolver* realResolver, EventLoop*) : realResolver(realResolver) {
}

CachingDomainNameResolver::~CachingDomainNameResolver() {

}

DomainNameServiceQuery::ref CachingDomainNameResolver::createServiceQuery(const std::string& serviceLookupPrefix, const std::string& domain) {
    //TODO: Cache
    return realResolver->createServiceQuery(serviceLookupPrefix, domain);
}

DomainNameAddressQuery::ref CachingDomainNameResolver::createAddressQuery(const std::string& name) {
    //TODO: Cache
    return realResolver->createAddressQuery(name);
}

}
