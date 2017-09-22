#ifndef JXMPP_VERSION_H
#define JXMPP_VERSION_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API Version : public Payload {
        public:
            Version(const std::string& name = "", const std::string& version = "", const std::string& os = "") : name_(name), version_(version), os_(os) { }

            const std::string& getName() const { return name_; }
            const std::string& getVersion() const { return version_; }
            const std::string& getOS() const { return os_; }

        private:
            std::string name_;
            std::string version_;
            std::string os_;
    };
}

#endif // JXMPP_VERSION_H
