#ifndef JXMPP_AVAHIQUERY_H
#define JXMPP_AVAHIQUERY_H

#include <memory>

#include <JXMPP/EventLoop/EventOwner.h>

namespace JXMPP {
    class AvahiQuerier;
    class EventLoop;

    class AvahiQuery :
            public EventOwner,
            public std::enable_shared_from_this<AvahiQuery> {
        public:
            AvahiQuery(std::shared_ptr<AvahiQuerier>, EventLoop* eventLoop);
            virtual ~AvahiQuery();

        protected:
            std::shared_ptr<AvahiQuerier> querier;
            EventLoop* eventLoop;
    };
}

#endif // JXMPP_AVAHIQUERY_H
