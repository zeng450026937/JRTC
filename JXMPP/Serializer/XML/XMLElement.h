#ifndef JXMPP_XMLELEMENT_H
#define JXMPP_XMLELEMENT_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Serializer/XML/XMLNode.h>

namespace JXMPP {
    class JXMPP_API XMLElement : public XMLNode {
        public:
            typedef std::shared_ptr<XMLElement> ref;

            XMLElement(const std::string& tag, const std::string& xmlns = "", const std::string& text = "");

            void setAttribute(const std::string& attribute, const std::string& value);
            void addNode(std::shared_ptr<XMLNode> node);

            virtual std::string serialize();

        private:
            std::string tag_;
            std::map<std::string, std::string> attributes_;
            std::vector< std::shared_ptr<XMLNode> > childNodes_;
    };
}

#endif // JXMPP_XMLELEMENT_H
