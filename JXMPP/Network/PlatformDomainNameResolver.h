#ifndef JXMPP_PLATFORMDOMAINNAMERESOLVER_H
#define JXMPP_PLATFORMDOMAINNAMERESOLVER_H

#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Atomic.h>
#include <JXMPP/Network/DomainNameAddressQuery.h>
#include <JXMPP/Network/DomainNameResolver.h>
#include <JXMPP/Network/DomainNameServiceQuery.h>
#include <JXMPP/Network/PlatformDomainNameQuery.h>

namespace JXMPP {
    class IDNConverter;
    class EventLoop;

    class JXMPP_API PlatformDomainNameResolver : public DomainNameResolver {
        public:
            PlatformDomainNameResolver(IDNConverter* idnConverter, EventLoop* eventLoop);
            virtual ~PlatformDomainNameResolver();

            virtual DomainNameServiceQuery::ref createServiceQuery(const std::string& serviceLookupPrefix, const std::string& domain);
            virtual DomainNameAddressQuery::ref createAddressQuery(const std::string& name);

        private:
            void run();
            void addQueryToQueue(PlatformDomainNameQuery::ref);

        private:
            friend class PlatformDomainNameServiceQuery;
            friend class PlatformDomainNameAddressQuery;
            IDNConverter* idnConverter;
            EventLoop* eventLoop;
            Atomic<bool> stopRequested;
            std::thread* thread;
            std::deque<PlatformDomainNameQuery::ref> queue;
            std::mutex queueMutex;
            std::condition_variable queueNonEmpty;
    };
}

#endif // JXMPP_PLATFORMDOMAINNAMERESOLVER_H
