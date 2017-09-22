#ifndef JXMPP_GETVCARDREQUEST_H
#define JXMPP_GETVCARDREQUEST_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/VCard.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API GetVCardRequest : public GenericRequest<VCard> {
        public:
            typedef std::shared_ptr<GetVCardRequest> ref;

            static ref create(const JID& jid, IQRouter* router) {
                return ref(new GetVCardRequest(jid, router));
            }

        private:
            GetVCardRequest(const JID& jid, IQRouter* router) : GenericRequest<VCard>(IQ::Get, jid, std::make_shared<VCard>(), router) {
            }
    };
}

#endif // JXMPP_GETVCARDREQUEST_H
