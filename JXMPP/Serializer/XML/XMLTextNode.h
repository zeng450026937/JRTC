#ifndef JXMPP_XMLTEXTNODE_H
#define JXMPP_XMLTEXTNODE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/String.h>
#include <JXMPP/Serializer/XML/XMLNode.h>

namespace JXMPP {
    class JXMPP_API XMLTextNode : public XMLNode {
        public:
            typedef std::shared_ptr<XMLTextNode> ref;

            XMLTextNode(const std::string& text) : text_(text) {
                String::replaceAll(text_, '&', "&amp;"); // Should come first
                String::replaceAll(text_, '<', "&lt;");
                String::replaceAll(text_, '>', "&gt;");
            }

            std::string serialize() {
                return text_;
            }

            static ref create(const std::string& text) {
                return ref(new XMLTextNode(text));
            }

        private:
            std::string text_;
    };
}

#endif // JXMPP_XMLTEXTNODE_H
