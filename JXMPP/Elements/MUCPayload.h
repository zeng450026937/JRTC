#ifndef JXMPP_MUCPAYLOAD_H
#define JXMPP_MUCPAYLOAD_H

#include <string>

#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API MUCPayload : public Payload {
        public:
            typedef std::shared_ptr<MUCPayload> ref;

            MUCPayload() {
                maxChars_ = -1;
                maxStanzas_ = -1;
                seconds_ = -1;
            }

            void setMaxChars(int maxChars) {
                maxChars_ = maxChars;
            }

            void setMaxStanzas(int maxStanzas) {
                maxStanzas_ = maxStanzas;
            }

            void setSeconds(int seconds) {
                seconds_ = seconds;
            }

            void setSince(boost::posix_time::ptime since) {
                since_ = since;
            }

            void setPassword(const std::string& password) {
                password_ = password;
            }

            int getMaxChars() const{
                return maxChars_;
            }

            int getMaxStanzas() const{
                return maxStanzas_;
            }

            int getSeconds() const {
                return seconds_;
            }

            const boost::optional<std::string>& getPassword() const {
                return password_;
            }

            const boost::posix_time::ptime& getSince() const {
                return since_;
            }

        private:
            int maxChars_;
            int maxStanzas_;
            int seconds_;
            boost::posix_time::ptime since_;
            boost::optional<std::string> password_;
    };
}

#endif // JXMPP_MUCPAYLOAD_H
