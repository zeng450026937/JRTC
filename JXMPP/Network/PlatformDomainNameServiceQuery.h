#ifndef JXMPP_PLATFORMDOMAINNAMESERVICEQUERY_H
#define JXMPP_PLATFORMDOMAINNAMESERVICEQUERY_H

#include <memory>
#include <string>

#include <JXMPP/EventLoop/EventOwner.h>
#include <JXMPP/Network/DomainNameServiceQuery.h>
#include <JXMPP/Network/PlatformDomainNameQuery.h>

namespace JXMPP {
    class EventLoop;

    class PlatformDomainNameServiceQuery : public DomainNameServiceQuery, public PlatformDomainNameQuery, public std::enable_shared_from_this<PlatformDomainNameServiceQuery>, public EventOwner {
        public:
            PlatformDomainNameServiceQuery(const boost::optional<std::string>& serviceName, EventLoop* eventLoop, PlatformDomainNameResolver* resolver);
            virtual ~PlatformDomainNameServiceQuery();

            virtual void run();

        private:
            void runBlocking();
            void emitError();

        private:
            EventLoop* eventLoop;
            std::string service;
            bool serviceValid;
    };
}

#endif // JXMPP_PLATFORMDOMAINNAMESERVICEQUERY_H
