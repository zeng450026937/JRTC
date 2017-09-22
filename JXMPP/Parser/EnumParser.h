#ifndef JXMPP_ENUMPARSER_H
#define JXMPP_ENUMPARSER_H

#include <cassert>
#include <map>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    template<typename T>
    class JXMPP_API EnumParser {
        public:
            EnumParser() {
            }

            EnumParser& operator()(T value, const std::string& text) {
                values[text] = value;
                return *this;
            }

            boost::optional<T> parse(const std::string& value) {
                typename std::map<std::string, T>::const_iterator i = values.find(value);
                return i == values.end() ? boost::optional<T>() : i->second;
            }

        private:
            std::map<std::string, T> values;
    };
}

#endif // JXMPP_ENUMPARSER_H
