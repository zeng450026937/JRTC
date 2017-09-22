#ifndef JXMPP_GETDISCOITEMSREQUEST_H
#define JXMPP_GETDISCOITEMSREQUEST_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoItems.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API GetDiscoItemsRequest : public GenericRequest<DiscoItems> {
        public:
            typedef std::shared_ptr<GetDiscoItemsRequest> ref;

            static ref create(const JID& jid, IQRouter* router) {
                return ref(new GetDiscoItemsRequest(jid, router));
            }

            static ref create(const JID& jid, const std::string& node, IQRouter* router) {
                return ref(new GetDiscoItemsRequest(jid, node, router));
            }

        private:
            GetDiscoItemsRequest(const JID& jid, IQRouter* router) :
                    GenericRequest<DiscoItems>(IQ::Get, jid, std::make_shared<DiscoItems>(), router) {
            }

            GetDiscoItemsRequest(const JID& jid, const std::string& node, IQRouter* router) :
                GenericRequest<DiscoItems>(IQ::Get, jid, std::make_shared<DiscoItems>(), router) {
                getPayloadGeneric()->setNode(node);
            }
    };
}

#endif // JXMPP_GETDISCOITEMSREQUEST_H
