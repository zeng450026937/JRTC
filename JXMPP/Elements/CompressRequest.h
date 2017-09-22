#ifndef JXMPP_COMPRESSREQUEST_H
#define JXMPP_COMPRESSREQUEST_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API CompressRequest : public ToplevelElement
    {
        public:
            CompressRequest(const std::string& method = "") : method_(method) {}

            const std::string& getMethod() const {
                return method_;
            }

            void setMethod(const std::string& method) {
                method_ = method;
            }

        private:
            std::string method_;
    };
}

#endif // JXMPP_COMPRESSREQUEST_H
