#ifndef JXMPP_EVENT_H
#define JXMPP_EVENT_H

#include <memory>

#include <boost/function.hpp>

#include <JXMPP/EventLoop/EventOwner.h>

namespace JXMPP {
    class Event {
        public:
            Event(std::shared_ptr<EventOwner> owner, const boost::function<void()>& callback) : id(~0U), owner(owner), callback(callback) {
            }

            bool operator==(const Event& o) const {
                return o.id == id;
            }

            unsigned int id;
            std::shared_ptr<EventOwner> owner;
            boost::function<void()> callback;
    };
}

std::ostream& operator<<(std::ostream& os, const JXMPP::Event& e);

#endif // JXMPP_EVENT_H
