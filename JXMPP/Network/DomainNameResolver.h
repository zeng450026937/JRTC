#ifndef JXMPP_DOMAINNAMERESOLVER_H
#define JXMPP_DOMAINNAMERESOLVER_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class DomainNameServiceQuery;
    class DomainNameAddressQuery;


    class JXMPP_API DomainNameResolver {
        public:
            virtual ~DomainNameResolver();

            virtual std::shared_ptr<DomainNameServiceQuery> createServiceQuery(const std::string& serviceLookupPrefix, const std::string& domain) = 0;
            virtual std::shared_ptr<DomainNameAddressQuery> createAddressQuery(const std::string& name) = 0;
    };
}

#endif // JXMPP_DOMAINNAMERESOLVER_H
