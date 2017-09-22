#ifndef JXMPP_ENABLECARBONSREQUEST_H
#define JXMPP_ENABLECARBONSREQUEST_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsEnable.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API EnableCarbonsRequest : public GenericRequest<CarbonsEnable> {
        public:
            typedef std::shared_ptr<EnableCarbonsRequest> ref;

            static ref create(IQRouter* router) {
                return ref(new EnableCarbonsRequest(router));
            }

        private:
            EnableCarbonsRequest(IQRouter* router) : GenericRequest<CarbonsEnable>(IQ::Set, JID(), std::make_shared<CarbonsEnable>(), router) {
            }
    };
}

#endif // JXMPP_ENABLECARBONSREQUEST_H
