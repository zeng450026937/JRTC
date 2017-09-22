#include <JXMPP/Serializer/PayloadSerializers/UnitTest/PayloadsSerializer.h>

#include <cppunit/extensions/HelperMacros.h>

#include <JXMPP/Serializer/PayloadSerializer.h>

namespace JXMPP {

std::string PayloadsSerializer::serialize(std::shared_ptr<Payload> payload) {
    PayloadSerializer* serializer = serializers.getPayloadSerializer(payload);
    if (serializer) {
        return serializer->serialize(payload);
    }
    else {
        CPPUNIT_ASSERT(false);
        return "";
    }
}


}
