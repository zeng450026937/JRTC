#ifndef JXMPP_DIGESTMD5PROPERTIES_H
#define JXMPP_DIGESTMD5PROPERTIES_H

#include <map>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>

namespace JXMPP {
    class JXMPP_API DIGESTMD5Properties {
        public:
            DIGESTMD5Properties();

            boost::optional<std::string> getValue(const std::string& key) const;

            void setValue(const std::string& key, const std::string& value);

            ByteArray serialize() const;

            static DIGESTMD5Properties parse(const ByteArray&);

        private:
            static bool isQuoted(const std::string& property);

        private:
            typedef std::multimap<std::string, ByteArray> DIGESTMD5PropertiesMap;
            DIGESTMD5PropertiesMap properties;
    };
}

#endif // JXMPP_DIGESTMD5PROPERTIES_H
