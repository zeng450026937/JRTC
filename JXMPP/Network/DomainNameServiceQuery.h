#ifndef JXMPP_DOMAINNAMESERVICEQUERY_H
#define JXMPP_DOMAINNAMESERVICEQUERY_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/DomainNameResolveError.h>

namespace JXMPP {
    class RandomGenerator;

    class JXMPP_API DomainNameServiceQuery {
        public:
            typedef std::shared_ptr<DomainNameServiceQuery> ref;

            struct Result {
                Result(const std::string& hostname = "", int port = -1, int priority = -1, int weight = -1) : hostname(hostname), port(port), priority(priority), weight(weight) {}
                std::string hostname;
                int port;
                int priority;
                int weight;
            };

            virtual ~DomainNameServiceQuery();

            virtual void run() = 0;
            static void sortResults(std::vector<DomainNameServiceQuery::Result>& queries, RandomGenerator& generator);

            boost::signals2::signal<void (const std::vector<Result>&)> onResult;
    };
}

#endif // JXMPP_DOMAINNAMESERVICEQUERY_H
