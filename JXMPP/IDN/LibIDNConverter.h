#ifndef JXMPP_LIBIDNCONVERTER_H
#define JXMPP_LIBIDNCONVERTER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/IDN/IDNConverter.h>

namespace JXMPP {
    class JXMPP_API LibIDNConverter : public IDNConverter {
        public:
            virtual std::string getStringPrepared(const std::string& s, StringPrepProfile profile) override;
            virtual SafeByteArray getStringPrepared(const SafeByteArray& s, StringPrepProfile profile) override;

            virtual boost::optional<std::string> getIDNAEncoded(const std::string& s) override;
    };
}

#endif // JXMPP_LIBIDNCONVERTER_H
