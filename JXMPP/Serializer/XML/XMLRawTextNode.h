#ifndef JXMPP_XMLRAWTEXTNODE_H
#define JXMPP_XMLRAWTEXTNODE_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Serializer/XML/XMLNode.h>

namespace JXMPP {
    class JXMPP_API XMLRawTextNode : public XMLNode {
        public:
            XMLRawTextNode(const std::string& text) : text_(text) {
            }

            std::string serialize() {
                return text_;
            }

        private:
            std::string text_;
    };
}

#endif // JXMPP_XMLRAWTEXTNODE_H
