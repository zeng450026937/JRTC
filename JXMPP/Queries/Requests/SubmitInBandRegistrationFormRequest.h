#ifndef JXMPP_SUBMITINBANDREGISTRATIONFORMREQUEST_H
#define JXMPP_SUBMITINBANDREGISTRATIONFORMREQUEST_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/InBandRegistrationPayload.h>
#include <JXMPP/Queries/Request.h>

namespace JXMPP {
    class JXMPP_API SetInBandRegistrationRequest : public Request {
        public:
            typedef std::shared_ptr<SetInBandRegistrationRequest> ref;

            static ref create(const JID& to, InBandRegistrationPayload::ref payload, IQRouter* router) {
                return ref(new SetInBandRegistrationRequest(to, payload, router));
            }

        private:
            SetInBandRegistrationRequest(const JID& to, InBandRegistrationPayload::ref payload, IQRouter* router) : Request(IQ::Set, to, InBandRegistrationPayload::ref(payload), router) {
            }

            virtual void handleResponse(std::shared_ptr<Payload> payload, ErrorPayload::ref error) {
                onResponse(payload, error);
            }

        public:
            boost::signals2::signal<void (std::shared_ptr<Payload>, ErrorPayload::ref)> onResponse;
    };
}

#endif // JXMPP_SUBMITINBANDREGISTRATIONFORMREQUEST_H
