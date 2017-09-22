#ifndef JXMPP_GETSECURITYLABELSCATALOGREQUEST_H
#define JXMPP_GETSECURITYLABELSCATALOGREQUEST_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SecurityLabelsCatalog.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API GetSecurityLabelsCatalogRequest : public GenericRequest<SecurityLabelsCatalog> {
        public:
            typedef std::shared_ptr<GetSecurityLabelsCatalogRequest> ref;

            static ref create(const JID& recipient, IQRouter* router) {
                return ref(new GetSecurityLabelsCatalogRequest(recipient, router));
            }

        private:
            GetSecurityLabelsCatalogRequest(
                    const JID& recipient,
                    IQRouter* router) :
                        GenericRequest<SecurityLabelsCatalog>(
                            IQ::Get, JID(), std::make_shared<SecurityLabelsCatalog>(recipient), router) {
            }
    };
}

#endif // JXMPP_GETSECURITYLABELSCATALOGREQUEST_H
