#ifndef JXMPP_GETINBANDREGISTRATIONFORMREQUEST_H
#define JXMPP_GETINBANDREGISTRATIONFORMREQUEST_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/InBandRegistrationPayload.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API GetInBandRegistrationFormRequest : public GenericRequest<InBandRegistrationPayload> {
        public:
            typedef std::shared_ptr<GetInBandRegistrationFormRequest> ref;

            static ref create(const JID& to, IQRouter* router) {
                return ref(new GetInBandRegistrationFormRequest(to, router));
            }

        private:
            GetInBandRegistrationFormRequest(const JID& to, IQRouter* router) : GenericRequest<InBandRegistrationPayload>(IQ::Get, to, InBandRegistrationPayload::ref(new InBandRegistrationPayload()), router) {
            }
    };
}

#endif // JXMPP_GETINBANDREGISTRATIONFORMREQUEST_H
