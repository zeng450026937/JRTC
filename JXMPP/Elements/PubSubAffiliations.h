#ifndef JXMPP_PUBSUBAFFILIATIONS_H
#define JXMPP_PUBSUBAFFILIATIONS_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubAffiliation.h>
#include <JXMPP/Elements/PubSubPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubAffiliations : public PubSubPayload {
        public:

            PubSubAffiliations();

            virtual ~PubSubAffiliations();

            const boost::optional< std::string >& getNode() const {
                return node;
            }

            void setNode(const boost::optional< std::string >& value) {
                this->node = value ;
            }

            const std::vector< std::shared_ptr<PubSubAffiliation> >& getAffiliations() const {
                return affiliations;
            }

            void setAffiliations(const std::vector< std::shared_ptr<PubSubAffiliation> >& value) {
                this->affiliations = value ;
            }

            void addAffiliation(std::shared_ptr<PubSubAffiliation> value) {
                this->affiliations.push_back(value);
            }


        private:
            boost::optional< std::string > node;
            std::vector< std::shared_ptr<PubSubAffiliation> > affiliations;
    };
}

#endif // JXMPP_PUBSUBAFFILIATIONS_H
