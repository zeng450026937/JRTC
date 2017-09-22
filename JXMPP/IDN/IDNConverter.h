#ifndef JXMPP_IDNCONVERTER_H
#define JXMPP_IDNCONVERTER_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API IDNConverter {
        public:
            virtual ~IDNConverter();

            enum StringPrepProfile {
                NamePrep,
                XMPPNodePrep,
                XMPPResourcePrep,
                SASLPrep
            };

            virtual std::string getStringPrepared(const std::string& s, StringPrepProfile profile) = 0;
            virtual SafeByteArray getStringPrepared(const SafeByteArray& s, StringPrepProfile profile) = 0;

            // Thread-safe
            virtual boost::optional<std::string> getIDNAEncoded(const std::string& s) = 0;
    };
}

#endif // JXMPP_IDNCONVERTER_H
