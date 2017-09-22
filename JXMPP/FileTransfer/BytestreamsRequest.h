#ifndef JXMPP_BYTESTREAMSREQUEST_H
#define JXMPP_BYTESTREAMSREQUEST_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Bytestreams.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API BytestreamsRequest : public GenericRequest<Bytestreams> {
        public:
            typedef std::shared_ptr<BytestreamsRequest> ref;

            static ref create(const JID& jid, std::shared_ptr<Bytestreams> payload, IQRouter* router) {
                return ref(new BytestreamsRequest(jid, payload, router));
            }

            static ref create(const JID& from, const JID& to, std::shared_ptr<Bytestreams> payload, IQRouter* router) {
                return ref(new BytestreamsRequest(from, to, payload, router));
            }

        private:
            BytestreamsRequest(const JID& jid, std::shared_ptr<Bytestreams> payload, IQRouter* router) : GenericRequest<Bytestreams>(IQ::Set, jid, payload, router) {
            }

            BytestreamsRequest(const JID& from, const JID& to, std::shared_ptr<Bytestreams> payload, IQRouter* router) : GenericRequest<Bytestreams>(IQ::Set, from, to, payload, router) {
            }
    };
}

#endif // JXMPP_BYTESTREAMSREQUEST_H
