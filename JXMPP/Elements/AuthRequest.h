#ifndef JXMPP_AUTHREQUEST_H
#define JXMPP_AUTHREQUEST_H

#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API AuthRequest : public ToplevelElement {
        public:
            AuthRequest(const std::string& mechanism = "") : mechanism_(mechanism) {
            }

            AuthRequest(const std::string& mechanism, const SafeByteArray& message) :
                    mechanism_(mechanism), message_(message) {
            }

            AuthRequest(const std::string& mechanism, const boost::optional<SafeByteArray>& message) :
                    mechanism_(mechanism), message_(message) {
            }

            const boost::optional<SafeByteArray>& getMessage() const {
                return message_;
            }

            void setMessage(const SafeByteArray& message) {
                message_ = boost::optional<SafeByteArray>(message);
            }

            const std::string& getMechanism() const {
                return mechanism_;
            }

            void setMechanism(const std::string& mechanism) {
                mechanism_ = mechanism;
            }

        private:
            std::string mechanism_;
            boost::optional<SafeByteArray> message_;
    };
}

#endif // JXMPP_AUTHREQUEST_H
