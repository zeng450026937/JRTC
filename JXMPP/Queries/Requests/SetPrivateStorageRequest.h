#ifndef JXMPP_SETPRIVATESTORAGEREQUEST_H
#define JXMPP_SETPRIVATESTORAGEREQUEST_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/PrivateStorage.h>
#include <JXMPP/Queries/Request.h>

namespace JXMPP {
    template<typename PAYLOAD_TYPE>
    class JXMPP_API SetPrivateStorageRequest : public Request {
        public:
            typedef std::shared_ptr<SetPrivateStorageRequest<PAYLOAD_TYPE> > ref;

            static ref create(std::shared_ptr<PAYLOAD_TYPE> payload, IQRouter* router) {
                return ref(new SetPrivateStorageRequest<PAYLOAD_TYPE>(payload, router));
            }

        private:
            SetPrivateStorageRequest(std::shared_ptr<PAYLOAD_TYPE> payload, IQRouter* router) : Request(IQ::Set, JID(), std::make_shared<PrivateStorage>(payload), router) {
            }

            virtual void handleResponse(std::shared_ptr<Payload>, ErrorPayload::ref error) {
                onResponse(error);
            }

        public:
            boost::signals2::signal<void (ErrorPayload::ref)> onResponse;
    };
}

#endif // JXMPP_SETPRIVATESTORAGEREQUEST_H
