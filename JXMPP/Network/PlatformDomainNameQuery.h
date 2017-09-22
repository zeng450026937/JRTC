#ifndef JXMPP_PLATFORMDOMAINNAMEQUERY_H
#define JXMPP_PLATFORMDOMAINNAMEQUERY_H

#include <memory>

namespace JXMPP {
    class PlatformDomainNameResolver;

    class PlatformDomainNameQuery {
        public:
            typedef std::shared_ptr<PlatformDomainNameQuery> ref;

            PlatformDomainNameQuery(PlatformDomainNameResolver* resolver) : resolver(resolver) {}
            virtual ~PlatformDomainNameQuery() {}

            virtual void runBlocking() = 0;

        protected:
            PlatformDomainNameResolver* getResolver() {
                return resolver;
            }

        private:
            PlatformDomainNameResolver* resolver;
    };
}

#endif // JXMPP_PLATFORMDOMAINNAMEQUERY_H
