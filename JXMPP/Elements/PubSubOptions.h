#ifndef JXMPP_PUBSUBOPTIONS_H
#define JXMPP_PUBSUBOPTIONS_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubPayload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API PubSubOptions : public PubSubPayload {
        public:

            PubSubOptions();

            virtual ~PubSubOptions();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            const JID& getJID() const {
                return jid;
            }

            void setJID(const JID& value) {
                this->jid = value ;
            }

            std::shared_ptr<Form> getData() const {
                return data;
            }

            void setData(std::shared_ptr<Form> value) {
                this->data = value ;
            }

            const boost::optional< std::string >& getSubscriptionID() const {
                return subscriptionID;
            }

            void setSubscriptionID(const boost::optional< std::string >& value) {
                this->subscriptionID = value ;
            }


        private:
            std::string node;
            JID jid;
            std::shared_ptr<Form> data;
            boost::optional< std::string > subscriptionID;
    };
}

#endif // JXMPP_PUBSUBOPTIONS_H
