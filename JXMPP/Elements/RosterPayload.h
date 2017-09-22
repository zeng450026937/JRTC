#ifndef JXMPP_ROSTERPAYLOAD_H
#define JXMPP_ROSTERPAYLOAD_H

#include <memory>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/RosterItemPayload.h>

namespace JXMPP {
    class JXMPP_API RosterPayload : public Payload {
        public:
            typedef std::shared_ptr<RosterPayload> ref;
            typedef std::vector<RosterItemPayload> RosterItemPayloads;

        public:
            RosterPayload() {}

            boost::optional<RosterItemPayload> getItem(const JID& jid) const;

            void addItem(const RosterItemPayload& item) {
                items_.push_back(item);
            }

            const RosterItemPayloads& getItems() const {
                return items_;
            }

            const boost::optional<std::string>& getVersion() const {
                return version_;
            }

            void setVersion(const std::string& version) {
                version_ = version;
            }

        private:
            RosterItemPayloads items_;
            boost::optional<std::string> version_;
    };
}

#endif // JXMPP_ROSTERPAYLOAD_H
