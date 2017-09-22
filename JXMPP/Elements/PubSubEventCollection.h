#ifndef JXMPP_PUBSUBEVENTCOLLECTION_H
#define JXMPP_PUBSUBEVENTCOLLECTION_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubEventAssociate.h>
#include <JXMPP/Elements/PubSubEventDisassociate.h>
#include <JXMPP/Elements/PubSubEventPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventCollection : public PubSubEventPayload {
        public:

            PubSubEventCollection();

            virtual ~PubSubEventCollection();

            const boost::optional< std::string >& getNode() const {
                return node;
            }

            void setNode(const boost::optional< std::string >& value) {
                this->node = value ;
            }

            std::shared_ptr<PubSubEventDisassociate> getDisassociate() const {
                return disassociate;
            }

            void setDisassociate(std::shared_ptr<PubSubEventDisassociate> value) {
                this->disassociate = value ;
            }

            std::shared_ptr<PubSubEventAssociate> getAssociate() const {
                return associate;
            }

            void setAssociate(std::shared_ptr<PubSubEventAssociate> value) {
                this->associate = value ;
            }


        private:
            boost::optional< std::string > node;
            std::shared_ptr<PubSubEventDisassociate> disassociate;
            std::shared_ptr<PubSubEventAssociate> associate;
    };
}

#endif // JXMPP_PUBSUBEVENTCOLLECTION_H
