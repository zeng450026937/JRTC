#ifndef JXMPP_FAKEDNSSDQUERY_H
#define JXMPP_FAKEDNSSDQUERY_H

#include <memory>

#include <JXMPP/EventLoop/EventOwner.h>

namespace JXMPP {
    class FakeDNSSDQuerier;

    class FakeDNSSDQuery :
            public EventOwner,
            public std::enable_shared_from_this<FakeDNSSDQuery> {
        public:
            FakeDNSSDQuery(std::shared_ptr<FakeDNSSDQuerier>);
            virtual ~FakeDNSSDQuery();

        protected:
            void run();
            void finish();

        protected:
            std::shared_ptr<FakeDNSSDQuerier> querier;
    };
}

#endif // JXMPP_FAKEDNSSDQUERY_H
