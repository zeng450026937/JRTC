#ifndef JXMPP_SOFTWAREVERSION_H
#define JXMPP_SOFTWAREVERSION_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API SoftwareVersion : public Payload {
        public:
            typedef std::shared_ptr<SoftwareVersion> ref;

            SoftwareVersion(
                    const std::string& name = "",
                    const std::string& version = "",
                    const std::string& os = "") :
                        name_(name), version_(version), os_(os) {}

            const std::string& getName() const {
                return name_;
            }

            void setName(const std::string& name) {
                name_ = name;
            }

            const std::string& getVersion() const {
                return version_;
            }

            void setVersion(const std::string& version) {
                version_ = version;
            }

            const std::string& getOS() const {
                return os_;
            }

            void setOS(const std::string& os) {
                os_ = os;
            }

        private:
            std::string name_;
            std::string version_;
            std::string os_;
    };
}

#endif // JXMPP_SOFTWAREVERSION_H
