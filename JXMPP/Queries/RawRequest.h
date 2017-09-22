#ifndef JXMPP_RAWREQUEST_H
#define JXMPP_RAWREQUEST_H

#include <memory>
#include <typeinfo>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/RawXMLPayload.h>
#include <JXMPP/Queries/Request.h>
#include <JXMPP/Serializer/PayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ErrorSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/FullPayloadSerializerCollection.h>

namespace JXMPP {
    class JXMPP_API RawRequest : public Request {
        public:
            typedef std::shared_ptr<RawRequest> ref;

            static ref create(IQ::Type type, const JID& recipient, const std::string& data, IQRouter* router) {
                return ref(new RawRequest(type, recipient, data, router));
            }

            boost::signals2::signal<void (const std::string&)> onResponse;

        private:
            RawRequest(IQ::Type type, const JID& receiver, const std::string& data, IQRouter* router) : Request(type, receiver, std::make_shared<RawXMLPayload>(data), router) {
            }

            virtual void handleResponse(std::shared_ptr<Payload> payload, ErrorPayload::ref error) {
                if (error) {
                    onResponse(ErrorSerializer(&serializers).serializePayload(error));
                }
                else {
                    assert(payload);
                    PayloadSerializer* serializer = serializers.getPayloadSerializer(payload);
                    assert(serializer);
                    onResponse(serializer->serialize(payload));
                }
            }

        private:
            FullPayloadSerializerCollection serializers;
    };
}

#endif // JXMPP_RAWREQUEST_H
