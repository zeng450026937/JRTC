#ifndef JXMPP_PARSERELEMENT_H
#define JXMPP_PARSERELEMENT_H

#include <memory>
#include <string>
#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/AttributeMap.h>

namespace JXMPP {
    class JXMPP_API ParserElement {
        public:
            typedef std::shared_ptr<ParserElement> ref;

            ParserElement(const std::string& name, const std::string& xmlns, const AttributeMap& attributes);
            virtual ~ParserElement();

            const std::string& getText() const { return text_; }
            const std::string& getName() const { return name_; }
            const std::string& getNamespace() const { return xmlns_; }
            const AttributeMap& getAttributes() const { return attributes_; }

            ParserElement::ref addChild(const std::string& name, const std::string& xmlns, const AttributeMap& attributes);
            void appendCharacterData(const std::string& data);

            std::vector<ParserElement::ref> getChildren(const std::string& name, const std::string& xmlns) const;
            const std::vector<ParserElement::ref>& getAllChildren() const {return children_;}
            ParserElement::ref getChild(const std::string& name, const std::string& xmlns) const;

            virtual operator bool() {
                return true;
            }

        private:
            std::vector<ParserElement::ref> children_;
            std::string name_;
            std::string xmlns_;
            AttributeMap attributes_;
            std::string text_;
    };
}

#endif // JXMPP_PARSERELEMENT_H
