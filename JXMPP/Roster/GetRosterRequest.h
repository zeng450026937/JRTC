#ifndef JXMPP_GETROSTERREQUEST_H
#define JXMPP_GETROSTERREQUEST_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterPayload.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API GetRosterRequest : public GenericRequest<RosterPayload> {
        public:
            typedef std::shared_ptr<GetRosterRequest> ref;

            static ref create(IQRouter* router) {
                return ref(new GetRosterRequest(router));
            }

            static ref create(IQRouter* router, const std::string& version) {
                ref result(new GetRosterRequest(router));
                result->getPayloadGeneric()->setVersion(version);
                return result;
            }

        private:
            GetRosterRequest(IQRouter* router) :
                    GenericRequest<RosterPayload>(IQ::Get, JID(), std::make_shared<RosterPayload>(), router) {
            }
    };
}

#endif // JXMPP_GETROSTERREQUEST_H
