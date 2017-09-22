#ifndef JXMPP_PUBSUBEVENTDELETE_H
#define JXMPP_PUBSUBEVENTDELETE_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubEventPayload.h>
#include <JXMPP/Elements/PubSubEventRedirect.h>

namespace JXMPP {
    class JXMPP_API PubSubEventDelete : public PubSubEventPayload {
        public:

            PubSubEventDelete();

            virtual ~PubSubEventDelete();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            std::shared_ptr<PubSubEventRedirect> getRedirects() const {
                return redirects;
            }

            void setRedirects(std::shared_ptr<PubSubEventRedirect> value) {
                this->redirects = value ;
            }


        private:
            std::string node;
            std::shared_ptr<PubSubEventRedirect> redirects;
    };
}

#endif // JXMPP_PUBSUBEVENTDELETE_H
