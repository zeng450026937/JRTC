#include <JXMPP/Serializer/PayloadSerializerCollection.h>

#include <algorithm>

#include <boost/bind.hpp>

#include <JXMPP/Serializer/PayloadSerializer.h>

namespace JXMPP {

PayloadSerializerCollection::PayloadSerializerCollection() {
}

PayloadSerializerCollection::~PayloadSerializerCollection() {
}

void PayloadSerializerCollection::addSerializer(PayloadSerializer* serializer) {
    serializers_.push_back(serializer);
}

void PayloadSerializerCollection::removeSerializer(PayloadSerializer* serializer) {
    serializers_.erase(std::remove(serializers_.begin(), serializers_.end(), serializer), serializers_.end());
}

PayloadSerializer* PayloadSerializerCollection::getPayloadSerializer(std::shared_ptr<Payload> payload) const {
    std::vector<PayloadSerializer*>::const_iterator i = std::find_if(
            serializers_.begin(), serializers_.end(),
            boost::bind(&PayloadSerializer::canSerialize, _1, payload));
    return (i != serializers_.end() ? *i : nullptr);
}

}
