#ifndef JXMPP_DNSSDRESOLVESERVICEQUERY_H
#define JXMPP_DNSSDRESOLVESERVICEQUERY_H

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDServiceID.h>

namespace JXMPP {
    class DNSSDResolveServiceQuery {
        public:
            struct Result {
                Result(const std::string& fullName, const std::string& host, int port, const ByteArray& info) :
                            fullName(fullName), host(host), port(port), info(info) {}
                std::string fullName;
                std::string host;
                int port;
                ByteArray info;
            };

            virtual ~DNSSDResolveServiceQuery();

            virtual void start() = 0;
            virtual void stop() = 0;

            boost::signals2::signal<void (const boost::optional<Result>&)> onServiceResolved;
    };
}

#endif // JXMPP_DNSSDRESOLVESERVICEQUERY_H
