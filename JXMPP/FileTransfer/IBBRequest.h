#ifndef JXMPP_IBBREQUEST_H
#define JXMPP_IBBREQUEST_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IBB.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class JXMPP_API IBBRequest : public GenericRequest<IBB> {
        public:
            typedef std::shared_ptr<IBBRequest> ref;

            static ref create(const JID& from, const JID& to, std::shared_ptr<IBB> payload, IQRouter* router) {
                return ref(new IBBRequest(from, to, payload, router));
            }

        private:
            IBBRequest(const JID& from, const JID& to, std::shared_ptr<IBB> payload, IQRouter* router) : GenericRequest<IBB>(IQ::Set, from, to, payload, router) {
            }
    };
}

#endif // JXMPP_IBBREQUEST_H
