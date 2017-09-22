#ifndef JXMPP_PLATFORMDOMAINNAMEADDRESSQUERY_H
#define JXMPP_PLATFORMDOMAINNAMEADDRESSQUERY_H

#include <memory>
#include <string>

#include <boost/asio/io_service.hpp>

#include <JXMPP/EventLoop/EventOwner.h>
#include <JXMPP/Network/DomainNameAddressQuery.h>
#include <JXMPP/Network/PlatformDomainNameQuery.h>

namespace JXMPP {
    class PlatformDomainNameResolver;
    class EventLoop;

    class PlatformDomainNameAddressQuery : public DomainNameAddressQuery, public PlatformDomainNameQuery, public std::enable_shared_from_this<PlatformDomainNameAddressQuery>, public EventOwner {
        public:
            PlatformDomainNameAddressQuery(const boost::optional<std::string>& host, EventLoop* eventLoop, PlatformDomainNameResolver*);
            virtual ~PlatformDomainNameAddressQuery();

            void run();

        private:
            void runBlocking();
            void emitError();

        private:
            boost::asio::io_service ioService;
            std::string hostname;
            bool hostnameValid;
            EventLoop* eventLoop;
    };
}

#endif // JXMPP_PLATFORMDOMAINNAMEADDRESSQUERY_H
