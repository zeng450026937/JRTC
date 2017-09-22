#ifndef JXMPP_CAPSINFO_H
#define JXMPP_CAPSINFO_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API CapsInfo : public Payload {
        public:
            typedef std::shared_ptr<CapsInfo> ref;

            CapsInfo(const std::string& node = "", const std::string& version = "", const std::string& hash = "sha-1") : node_(node), version_(version), hash_(hash) {}

            bool operator==(const CapsInfo& o) const {
                return o.node_ == node_ && o.version_ == version_ && o.hash_ == hash_;
            }

            bool operator<(const CapsInfo& o) const {
                if (o.node_ == node_) {
                    if (o.version_ == version_) {
                        return hash_ < o.hash_;
                    }
                    else {
                        return version_ < o.version_;
                    }
                }
                else {
                    return node_ < o.node_;
                }
            }

            const std::string& getNode() const { return node_; }
            void setNode(const std::string& node) {
                node_ = node;
            }

            const std::string& getVersion() const { return version_; }
            void setVersion(const std::string& version) {
                version_ = version;
            }

            const std::string& getHash() const { return hash_; }
            void setHash(const std::string& hash) {
                hash_ = hash;
            }

        private:
            std::string node_;
            std::string version_;
            std::string hash_;
    };
}

#endif // JXMPP_CAPSINFO_H
