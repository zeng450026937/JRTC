#ifndef JXMPP_SETVCARDREQUEST_H
#define JXMPP_SETVCARDREQUEST_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/VCard.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API SetVCardRequest : public GenericRequest<VCard> {
        public:
            typedef std::shared_ptr<SetVCardRequest> ref;

            static ref create(VCard::ref vcard, IQRouter* router) {
                return ref(new SetVCardRequest(vcard, router));
            }

        private:
            SetVCardRequest(VCard::ref vcard, IQRouter* router) : GenericRequest<VCard>(IQ::Set, JID(), vcard, router) {
            }
    };
}

#endif // JXMPP_SETVCARDREQUEST_H
