#ifndef JXMPP_PUBSUBSUBSCRIBE_H
#define JXMPP_PUBSUBSUBSCRIBE_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubOptions.h>
#include <JXMPP/Elements/PubSubPayload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API PubSubSubscribe : public PubSubPayload {
        public:

            PubSubSubscribe();

            virtual ~PubSubSubscribe();

            const boost::optional< std::string >& getNode() const {
                return node;
            }

            void setNode(const boost::optional< std::string >& value) {
                this->node = value ;
            }

            const JID& getJID() const {
                return jid;
            }

            void setJID(const JID& value) {
                this->jid = value ;
            }

            std::shared_ptr<PubSubOptions> getOptions() const {
                return options;
            }

            void setOptions(std::shared_ptr<PubSubOptions> value) {
                this->options = value ;
            }


        private:
            boost::optional< std::string > node;
            JID jid;
            std::shared_ptr<PubSubOptions> options;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIBE_H
