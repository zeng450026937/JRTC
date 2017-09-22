#include <JXMPP/Serializer/XMPPSerializer.h>

#include <cassert>
#include <memory>

#include <boost/bind.hpp>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Elements/ProtocolHeader.h>
#include <JXMPP/Serializer/AuthChallengeSerializer.h>
#include <JXMPP/Serializer/AuthFailureSerializer.h>
#include <JXMPP/Serializer/AuthRequestSerializer.h>
#include <JXMPP/Serializer/AuthResponseSerializer.h>
#include <JXMPP/Serializer/AuthSuccessSerializer.h>
#include <JXMPP/Serializer/ComponentHandshakeSerializer.h>
#include <JXMPP/Serializer/CompressFailureSerializer.h>
#include <JXMPP/Serializer/CompressRequestSerializer.h>
#include <JXMPP/Serializer/EnableStreamManagementSerializer.h>
#include <JXMPP/Serializer/IQSerializer.h>
#include <JXMPP/Serializer/MessageSerializer.h>
#include <JXMPP/Serializer/PresenceSerializer.h>
#include <JXMPP/Serializer/StanzaAckRequestSerializer.h>
#include <JXMPP/Serializer/StanzaAckSerializer.h>
#include <JXMPP/Serializer/StartTLSFailureSerializer.h>
#include <JXMPP/Serializer/StartTLSRequestSerializer.h>
#include <JXMPP/Serializer/StreamErrorSerializer.h>
#include <JXMPP/Serializer/StreamFeaturesSerializer.h>
#include <JXMPP/Serializer/StreamManagementEnabledSerializer.h>
#include <JXMPP/Serializer/StreamManagementFailedSerializer.h>
#include <JXMPP/Serializer/StreamResumeSerializer.h>
#include <JXMPP/Serializer/StreamResumedSerializer.h>
#include <JXMPP/Serializer/TLSProceedSerializer.h>

namespace JXMPP {

XMPPSerializer::XMPPSerializer(PayloadSerializerCollection* payloadSerializers, StreamType type, bool setExplictNSonTopLevelElements) : type_(type) {
    serializers_.push_back(std::make_shared<PresenceSerializer>(payloadSerializers, setExplictNSonTopLevelElements ? getDefaultNamespace() : boost::optional<std::string>()));
    serializers_.push_back(std::make_shared<IQSerializer>(payloadSerializers, setExplictNSonTopLevelElements ? getDefaultNamespace() : boost::optional<std::string>()));
    serializers_.push_back(std::make_shared<MessageSerializer>(payloadSerializers, setExplictNSonTopLevelElements ? getDefaultNamespace() : boost::optional<std::string>()));
    serializers_.push_back(std::make_shared<CompressRequestSerializer>());
    serializers_.push_back(std::make_shared<CompressFailureSerializer>());
    serializers_.push_back(std::make_shared<AuthRequestSerializer>());
    serializers_.push_back(std::make_shared<AuthFailureSerializer>());
    serializers_.push_back(std::make_shared<AuthSuccessSerializer>());
    serializers_.push_back(std::make_shared<AuthChallengeSerializer>());
    serializers_.push_back(std::make_shared<AuthResponseSerializer>());
    serializers_.push_back(std::make_shared<StartTLSRequestSerializer>());
    serializers_.push_back(std::make_shared<StartTLSFailureSerializer>());
    serializers_.push_back(std::make_shared<TLSProceedSerializer>());
    serializers_.push_back(std::make_shared<StreamFeaturesSerializer>());
    serializers_.push_back(std::make_shared<StreamErrorSerializer>());
    serializers_.push_back(std::make_shared<EnableStreamManagementSerializer>());
    serializers_.push_back(std::make_shared<StreamManagementEnabledSerializer>());
    serializers_.push_back(std::make_shared<StreamManagementFailedSerializer>());
    serializers_.push_back(std::make_shared<StreamResumeSerializer>());
    serializers_.push_back(std::make_shared<StreamResumedSerializer>());
    serializers_.push_back(std::make_shared<StanzaAckSerializer>());
    serializers_.push_back(std::make_shared<StanzaAckRequestSerializer>());
    serializers_.push_back(std::make_shared<ComponentHandshakeSerializer>());
}

std::string XMPPSerializer::serializeHeader(const ProtocolHeader& header) const {
    std::string result = "<?xml version=\"1.0\"?><stream:stream xmlns=\"" + getDefaultNamespace() + "\" xmlns:stream=\"http://etherx.jabber.org/streams\"";
    if (!header.getFrom().empty()) {
        result += " from=\"" + header.getFrom() + "\"";
    }
    if (!header.getTo().empty()) {
        result += " to=\"" + header.getTo() + "\"";
    }
    if (!header.getID().empty()) {
        result += " id=\"" + header.getID() + "\"";
    }
    if (!header.getVersion().empty()) {
        result += " version=\"" + header.getVersion() + "\"";
    }
    result += ">";
    return result;
}

SafeByteArray XMPPSerializer::serializeElement(std::shared_ptr<ToplevelElement> element) const {
    std::vector< std::shared_ptr<ElementSerializer> >::const_iterator i = std::find_if(serializers_.begin(), serializers_.end(), boost::bind(&ElementSerializer::canSerialize, _1, element));
    if (i != serializers_.end()) {
        return (*i)->serialize(element);
    }
    else {
        JXMPP_LOG(warning) << "Could not find serializer for " << typeid(*(element.get())).name() << std::endl;
        return createSafeByteArray("");
    }
}

std::string XMPPSerializer::serializeFooter() const {
    return "</stream:stream>";
}

std::string XMPPSerializer::getDefaultNamespace() const {
    switch (type_) {
        case ClientStreamType: return "jabber:client";
        case ServerStreamType: return "jabber:server";
        case ComponentStreamType: return "jabber:component:accept";
    }
    assert(false);
    return "";
}

}
