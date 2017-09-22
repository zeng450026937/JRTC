#ifndef JXMPP_PUBSUBOWNERAFFILIATIONS_H
#define JXMPP_PUBSUBOWNERAFFILIATIONS_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubOwnerAffiliation.h>
#include <JXMPP/Elements/PubSubOwnerPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerAffiliations : public PubSubOwnerPayload {
        public:

            PubSubOwnerAffiliations();

            virtual ~PubSubOwnerAffiliations();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            const std::vector< std::shared_ptr<PubSubOwnerAffiliation> >& getAffiliations() const {
                return affiliations;
            }

            void setAffiliations(const std::vector< std::shared_ptr<PubSubOwnerAffiliation> >& value) {
                this->affiliations = value ;
            }

            void addAffiliation(std::shared_ptr<PubSubOwnerAffiliation> value) {
                this->affiliations.push_back(value);
            }


        private:
            std::string node;
            std::vector< std::shared_ptr<PubSubOwnerAffiliation> > affiliations;
    };
}

#endif // JXMPP_PUBSUBOWNERAFFILIATIONS_H
