#ifndef JXMPP_PLATFORMDNSSDQUERIERFACTORY_H
#define JXMPP_PLATFORMDNSSDQUERIERFACTORY_H

#include <memory>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class DNSSDQuerier;
    class EventLoop;

    class JXMPP_API PlatformDNSSDQuerierFactory {
        public:
            PlatformDNSSDQuerierFactory(EventLoop* eventLoop);

            std::shared_ptr<DNSSDQuerier> createQuerier();

            bool canCreate();

        private:
            EventLoop* eventLoop;
    };
}

#endif // JXMPP_PLATFORMDNSSDQUERIERFACTORY_H
