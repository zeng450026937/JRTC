#ifndef JXMPP_PUBSUBDEFAULT_H
#define JXMPP_PUBSUBDEFAULT_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubDefault : public PubSubPayload {
        public:
            enum Type {
                None,
                Collection,
                Leaf
            };

            PubSubDefault();

            virtual ~PubSubDefault();

            const boost::optional< std::string >& getNode() const {
                return node;
            }

            void setNode(const boost::optional< std::string >& value) {
                this->node = value ;
            }

            Type getType() const {
                return type;
            }

            void setType(Type value) {
                this->type = value ;
            }


        private:
            boost::optional< std::string > node;
            Type type;
    };
}

#endif // JXMPP_PUBSUBDEFAULT_H
