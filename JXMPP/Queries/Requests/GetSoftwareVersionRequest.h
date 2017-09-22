#ifndef JXMPP_GETSOFTWAREVERSIONREQUEST_H
#define JXMPP_GETSOFTWAREVERSIONREQUEST_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SoftwareVersion.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API GetSoftwareVersionRequest : public GenericRequest<SoftwareVersion> {
        public:
            typedef std::shared_ptr<GetSoftwareVersionRequest> ref;

            static ref create(const JID& recipient, IQRouter* router) {
                return ref(new GetSoftwareVersionRequest(recipient, router));
            }

        private:
            GetSoftwareVersionRequest(
                    const JID& recipient,
                    IQRouter* router) :
                        GenericRequest<SoftwareVersion>(
                            IQ::Get, recipient, std::make_shared<SoftwareVersion>(), router) {
            }
    };
}

#endif // JXMPP_GETSOFTWAREVERSIONREQUEST_H
