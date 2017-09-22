#ifndef JXMPP_PUBSUBOWNERDELETE_H
#define JXMPP_PUBSUBOWNERDELETE_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubOwnerPayload.h>
#include <JXMPP/Elements/PubSubOwnerRedirect.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerDelete : public PubSubOwnerPayload {
        public:

            PubSubOwnerDelete();
            PubSubOwnerDelete(const std::string& node) : node(node) {}
            virtual ~PubSubOwnerDelete();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            std::shared_ptr<PubSubOwnerRedirect> getRedirect() const {
                return redirect;
            }

            void setRedirect(std::shared_ptr<PubSubOwnerRedirect> value) {
                this->redirect = value ;
            }


        private:
            std::string node;
            std::shared_ptr<PubSubOwnerRedirect> redirect;
    };
}

#endif // JXMPP_PUBSUBOWNERDELETE_H
