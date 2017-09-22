#ifndef JXMPP_STREAMINITIATIONREQUEST_H
#define JXMPP_STREAMINITIATIONREQUEST_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamInitiation.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API StreamInitiationRequest : public GenericRequest<StreamInitiation> {
        public:
            typedef std::shared_ptr<StreamInitiationRequest> ref;

            static ref create(const JID& jid, std::shared_ptr<StreamInitiation> payload, IQRouter* router) {
                return ref(new StreamInitiationRequest(jid, payload, router));
            }

            static ref create(const JID& from, const JID& to, std::shared_ptr<StreamInitiation> payload, IQRouter* router) {
                return ref(new StreamInitiationRequest(from, to, payload, router));
            }

        private:
            StreamInitiationRequest(const JID& jid, std::shared_ptr<StreamInitiation> payload, IQRouter* router) : GenericRequest<StreamInitiation>(IQ::Set, jid, payload, router) {
            }

            StreamInitiationRequest(const JID& from, const JID& to, std::shared_ptr<StreamInitiation> payload, IQRouter* router) : GenericRequest<StreamInitiation>(IQ::Set, from, to, payload, router) {
            }
    };
}

#endif // JXMPP_STREAMINITIATIONREQUEST_H
