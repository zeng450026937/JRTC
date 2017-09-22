#ifndef JXMPP_GETPRIVATESTORAGEREQUEST_H
#define JXMPP_GETPRIVATESTORAGEREQUEST_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/PrivateStorage.h>
#include <JXMPP/Queries/Request.h>

namespace JXMPP {
    template<typename PAYLOAD_TYPE>
    class JXMPP_API GetPrivateStorageRequest : public Request {
        public:
            typedef std::shared_ptr<GetPrivateStorageRequest<PAYLOAD_TYPE> > ref;

            static ref create(IQRouter* router) {
                return ref(new GetPrivateStorageRequest(router));
            }

        private:
            GetPrivateStorageRequest(IQRouter* router) : Request(IQ::Get, JID(), std::make_shared<PrivateStorage>(std::make_shared<PAYLOAD_TYPE>()), router) {
            }

            virtual void handleResponse(std::shared_ptr<Payload> payload, ErrorPayload::ref error) {
                std::shared_ptr<PrivateStorage> storage = std::dynamic_pointer_cast<PrivateStorage>(payload);
                if (storage) {
                    onResponse(std::dynamic_pointer_cast<PAYLOAD_TYPE>(storage->getPayload()), error);
                }
                else {
                    onResponse(std::shared_ptr<PAYLOAD_TYPE>(), error);
                }
            }

        public:
            boost::signals2::signal<void (std::shared_ptr<PAYLOAD_TYPE>, ErrorPayload::ref)> onResponse;
    };
}

#endif // JXMPP_GETPRIVATESTORAGEREQUEST_H
