#ifndef JXMPP_PUBSUBAFFILIATION_H
#define JXMPP_PUBSUBAFFILIATION_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubAffiliation : public Payload {
        public:
            enum Type {
                None,
                Member,
                Outcast,
                Owner,
                Publisher,
                PublishOnly
            };

            PubSubAffiliation();
            PubSubAffiliation(const std::string& node) : node(node), type(None) {}
            virtual ~PubSubAffiliation();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            Type getType() const {
                return type;
            }

            void setType(Type value) {
                this->type = value ;
            }


        private:
            std::string node;
            Type type;
    };
}

#endif // JXMPP_PUBSUBAFFILIATION_H
