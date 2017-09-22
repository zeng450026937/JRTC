#ifndef JXMPP_DEBUG_H
#define JXMPP_DEBUG_H

#include <iosfwd>

#include <JXMPP/Client/ClientSession.h>

namespace JXMPP {
    class ClientError;
    class Element;
}

JXMPP_API std::ostream& operator<<(std::ostream& os, const JXMPP::ClientError& error);

JXMPP_API std::ostream& operator<<(std::ostream& os, JXMPP::Element* ele);

JXMPP_API std::ostream& operator<<(std::ostream& os, JXMPP::ClientSession::State state);

#endif // JXMPP_DEBUG_H
