#ifndef JXMPP_SETROSTERREQUEST_H
#define JXMPP_SETROSTERREQUEST_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterPayload.h>
#include <JXMPP/Queries/Request.h>

namespace JXMPP {
    class JXMPP_API SetRosterRequest : public Request {
        public:
            typedef std::shared_ptr<SetRosterRequest> ref;

            static ref create(RosterPayload::ref payload, IQRouter* router) {
                return ref(new SetRosterRequest(JID(), payload, router));
            }

            static ref create(RosterPayload::ref payload, const JID& to, IQRouter* router) {
                return ref(new SetRosterRequest(to, payload, router));
            }

        private:
            SetRosterRequest(const JID& to, std::shared_ptr<RosterPayload> payload, IQRouter* router) : Request(IQ::Set, to, std::shared_ptr<RosterPayload>(payload), router) {
            }

            virtual void handleResponse(std::shared_ptr<Payload> /*payload*/, ErrorPayload::ref error) {
                onResponse(error);
            }

        public:
            boost::signals2::signal<void (ErrorPayload::ref)> onResponse;
    };
}

#endif // JXMPP_SETROSTERREQUEST_H
