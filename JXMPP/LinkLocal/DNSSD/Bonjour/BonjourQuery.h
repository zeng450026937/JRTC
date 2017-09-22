#ifndef JXMPP_BONJOURQUERY_H
#define JXMPP_BONJOURQUERY_H

#include <memory>
#include <mutex>

#include <dns_sd.h>

#include <JXMPP/EventLoop/EventOwner.h>

namespace JXMPP {
    class BonjourQuerier;
    class EventLoop;

    class BonjourQuery :
            public EventOwner,
            public std::enable_shared_from_this<BonjourQuery> {
        public:
            BonjourQuery(std::shared_ptr<BonjourQuerier>, EventLoop* eventLoop);
            virtual ~BonjourQuery();

            void processResult();
            int getSocketID() const;

        protected:
            void run();
            void finish();

        protected:
            EventLoop* eventLoop;
            std::shared_ptr<BonjourQuerier> querier;
            mutable std::mutex sdRefMutex;
            DNSServiceRef sdRef;
    };
}

#endif // JXMPP_BONJOURQUERY_H
