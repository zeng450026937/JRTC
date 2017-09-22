#ifndef JXMPP_PUBSUBOWNERAFFILIATION_H
#define JXMPP_PUBSUBOWNERAFFILIATION_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerAffiliation : public Payload {
        public:
            enum Type {
                None,
                Member,
                Outcast,
                Owner,
                Publisher,
                PublishOnly
            };

            PubSubOwnerAffiliation();

            virtual ~PubSubOwnerAffiliation();

            const JID& getJID() const {
                return jid;
            }

            void setJID(const JID& value) {
                this->jid = value ;
            }

            Type getType() const {
                return type;
            }

            void setType(Type value) {
                this->type = value ;
            }


        private:
            JID jid;
            Type type;
    };
}

#endif // JXMPP_PUBSUBOWNERAFFILIATION_H
