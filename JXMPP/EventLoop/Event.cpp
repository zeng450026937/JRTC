#include <JXMPP/EventLoop/Event.h>

#include <iostream>
#include <typeinfo>

std::ostream& operator<<(std::ostream& os, const JXMPP::Event& e) {
    os << "Event(" << e.id << ",";
    if (e.owner) {
        os << typeid(*e.owner.get()).name();
    }
    else {
        os << "null";
    }
    os << ")";
    return os;
}
