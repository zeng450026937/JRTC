#ifndef JXMPP_GETDISCOINFOREQUEST_H
#define JXMPP_GETDISCOINFOREQUEST_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API GetDiscoInfoRequest : public GenericRequest<DiscoInfo> {
        public:
            typedef std::shared_ptr<GetDiscoInfoRequest> ref;

            static ref create(const JID& jid, IQRouter* router) {
                return ref(new GetDiscoInfoRequest(jid, router));
            }

            static ref create(const JID& jid, const std::string& node, IQRouter* router) {
                return ref(new GetDiscoInfoRequest(jid, node, router));
            }

        private:
            GetDiscoInfoRequest(const JID& jid, IQRouter* router) :
                    GenericRequest<DiscoInfo>(IQ::Get, jid, std::make_shared<DiscoInfo>(), router) {
            }

            GetDiscoInfoRequest(const JID& jid, const std::string& node, IQRouter* router) :
                    GenericRequest<DiscoInfo>(IQ::Get, jid, std::make_shared<DiscoInfo>(), router) {
                getPayloadGeneric()->setNode(node);
            }
    };
}

#endif // JXMPP_GETDISCOINFOREQUEST_H
