#ifndef JXMPP_RESOURCEBIND_H
#define JXMPP_RESOURCEBIND_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API ResourceBind : public Payload {
        public:
            ResourceBind() {}

            void setJID(const JID& jid) {
                jid_ = jid;
            }

            const JID& getJID() const {
                return jid_;
            }

            void setResource(const std::string& resource) {
                resource_ = resource;
            }

            const std::string& getResource() const {
                return resource_;
            }

        private:
            JID jid_;
            std::string resource_;
    };
}

#endif // JXMPP_RESOURCEBIND_H
