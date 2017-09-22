#ifndef JXMPP_ATTRIBUTEMAP_H
#define JXMPP_ATTRIBUTEMAP_H

#include <map>
#include <string>
#include <vector>

#include <boost/optional/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/Attribute.h>

namespace JXMPP {
    class JXMPP_API AttributeMap {
        public:
            class Entry {
                public:
                    Entry(const Attribute& attribute, const std::string& value) : attribute(attribute), value(value) {
                    }

                    const Attribute& getAttribute() const {
                        return attribute;
                    }

                    const std::string& getValue() const {
                        return value;
                    }

                private:
                    Attribute attribute;
                    std::string value;
            };

            AttributeMap();

            std::string getAttribute(const std::string& attribute, const std::string& ns = "") const;
            bool getBoolAttribute(const std::string& attribute, bool defaultValue = false) const;
            boost::optional<std::string> getAttributeValue(const std::string&) const;

            void addAttribute(const std::string& name, const std::string& ns, const std::string& value);

            const std::vector<Entry>& getEntries() const {
                return attributes;
            }

        private:
            typedef std::vector<Entry> AttributeValueMap;
            AttributeValueMap attributes;
    };
}

#endif // JXMPP_ATTRIBUTEMAP_H
