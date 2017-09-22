#ifndef JXMPP_DOMAINNAMEADDRESSQUERY_H
#define JXMPP_DOMAINNAMEADDRESSQUERY_H

#include <memory>

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Network/DomainNameResolveError.h>
#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class DomainNameAddressQuery {
        public:
            typedef std::shared_ptr<DomainNameAddressQuery> ref;

            virtual ~DomainNameAddressQuery();

            virtual void run() = 0;

            boost::signals2::signal<void (const std::vector<HostAddress>&, boost::optional<DomainNameResolveError>)> onResult;
    };
}

#endif // JXMPP_DOMAINNAMEADDRESSQUERY_H
