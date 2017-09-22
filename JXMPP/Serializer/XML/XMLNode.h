#ifndef JXMPP_XMLNODE_H
#define JXMPP_XMLNODE_H

#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API XMLNode {
        public:
            virtual ~XMLNode();

            virtual std::string serialize() = 0;
    };
}

#endif // JXMPP_XMLNODE_H
