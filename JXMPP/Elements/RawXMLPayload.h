#ifndef JXMPP_RAWXMLPAYLOAD_H
#define JXMPP_RAWXMLPAYLOAD_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API RawXMLPayload : public Payload {
        public:
            RawXMLPayload(const std::string& data = "") : rawXML_(data) {}

            void setRawXML(const std::string& data) {
                rawXML_ = data;
            }

            const std::string& getRawXML() const {
                return rawXML_;
            }

        private:
            std::string rawXML_;
    };
}

#endif // JXMPP_RAWXMLPAYLOAD_H
