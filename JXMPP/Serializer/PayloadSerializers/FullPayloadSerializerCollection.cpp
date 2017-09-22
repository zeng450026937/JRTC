#include <JXMPP/Serializer/PayloadSerializers/FullPayloadSerializerCollection.h>

#include <JXMPP/Elements/BlockListPayload.h>
#include <JXMPP/Elements/BlockPayload.h>
#include <JXMPP/Elements/UnblockPayload.h>
#include <JXMPP/Serializer/PayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/BlockSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/BodySerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/BytestreamsSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/CapsInfoSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/CarbonsDisableSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/CarbonsEnableSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/CarbonsPrivateSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/CarbonsReceivedSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/CarbonsSentSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ChatStateSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ClientStateSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/CommandSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/DelaySerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/DeliveryReceiptRequestSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/DeliveryReceiptSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/DiscoInfoSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/DiscoItemsSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ErrorSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ForwardedSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/IBBSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/IdleSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/InBandRegistrationPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/IsodeIQDelegationSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/JingleContentPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/JingleFileTransferDescriptionSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/JingleFileTransferFileInfoSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/JingleFileTransferHashSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/JingleIBBTransportPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/JinglePayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/JingleS5BTransportPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/LastSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MAMFinSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MAMQuerySerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MAMResultSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXJoinSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXDestroySerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXUpdateSubscriptionSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXParticipantSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXRegisterNickSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXCreateSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXSetNickSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXUserPreferenceSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MIXLeaveSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MUCAdminPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MUCDestroyPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MUCInvitationPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MUCOwnerPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MUCPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/MUCUserPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/NicknameSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PrioritySerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PrivateStorageSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubErrorSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerPubSubSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/RawXMLPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ReplaceSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ResourceBindSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ResultSetSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/RosterItemExchangeSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/RosterSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/S5BProxyRequestSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/SearchPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/SecurityLabelSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/SecurityLabelsCatalogSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/SoftwareVersionSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/StartSessionSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/StatusSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/StatusShowSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/StorageSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/StreamInitiationFileInfoSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/StreamInitiationSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/SubjectSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ThreadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/UserLocationSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/UserTuneSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/VCardSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/VCardUpdateSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/WhiteboardSerializer.h>

namespace JXMPP {

FullPayloadSerializerCollection::FullPayloadSerializerCollection() {
    serializers_.push_back(new IBBSerializer());
    serializers_.push_back(new BodySerializer());
    serializers_.push_back(new SubjectSerializer());
    serializers_.push_back(new ThreadSerializer());
    serializers_.push_back(new ChatStateSerializer());
    serializers_.push_back(new ClientStateSerializer());
    serializers_.push_back(new PrioritySerializer());
    serializers_.push_back(new ErrorSerializer(this));
    serializers_.push_back(new RosterSerializer());
    serializers_.push_back(new RosterItemExchangeSerializer());
    serializers_.push_back(new MUCPayloadSerializer());
    serializers_.push_back(new MUCDestroyPayloadSerializer());
    serializers_.push_back(new MUCAdminPayloadSerializer());
    serializers_.push_back(new MUCInvitationPayloadSerializer());
    serializers_.push_back(new MUCOwnerPayloadSerializer(this));
    serializers_.push_back(new MUCUserPayloadSerializer(this));
    serializers_.push_back(new SoftwareVersionSerializer());
    serializers_.push_back(new StatusSerializer());
    serializers_.push_back(new StatusShowSerializer());
    serializers_.push_back(new DiscoInfoSerializer());
    serializers_.push_back(new DiscoItemsSerializer());
    serializers_.push_back(new CapsInfoSerializer());
    serializers_.push_back(new BlockSerializer<BlockPayload>("block"));
    serializers_.push_back(new BlockSerializer<UnblockPayload>("unblock"));
    serializers_.push_back(new BlockSerializer<BlockListPayload>("blocklist"));
    serializers_.push_back(new ResourceBindSerializer());
    serializers_.push_back(new StartSessionSerializer());
    serializers_.push_back(new SecurityLabelSerializer());
    serializers_.push_back(new SecurityLabelsCatalogSerializer());
    serializers_.push_back(new StreamInitiationSerializer());
    serializers_.push_back(new BytestreamsSerializer());
    serializers_.push_back(new VCardSerializer());
    serializers_.push_back(new VCardUpdateSerializer());
    serializers_.push_back(new RawXMLPayloadSerializer());
    serializers_.push_back(new StorageSerializer());
    serializers_.push_back(new DelaySerializer());
    serializers_.push_back(new FormSerializer());
    serializers_.push_back(new PrivateStorageSerializer(this));
    serializers_.push_back(new CommandSerializer());
    serializers_.push_back(new InBandRegistrationPayloadSerializer());
    serializers_.push_back(new NicknameSerializer());
    serializers_.push_back(new SearchPayloadSerializer());
    serializers_.push_back(new ReplaceSerializer());
    serializers_.push_back(new LastSerializer());
    serializers_.push_back(new WhiteboardSerializer());
    serializers_.push_back(new UserLocationSerializer(this));
    serializers_.push_back(new UserTuneSerializer(this));
    serializers_.push_back(new IdleSerializer());

    serializers_.push_back(new StreamInitiationFileInfoSerializer());
    serializers_.push_back(new JingleFileTransferFileInfoSerializer());
    serializers_.push_back(new JingleContentPayloadSerializer());
    serializers_.push_back(new JingleFileTransferDescriptionSerializer());
    serializers_.push_back(new JingleFileTransferHashSerializer());
    serializers_.push_back(new JingleIBBTransportPayloadSerializer());
    serializers_.push_back(new JingleS5BTransportPayloadSerializer());
    serializers_.push_back(new JinglePayloadSerializer(this));
    serializers_.push_back(new S5BProxyRequestSerializer());
    serializers_.push_back(new DeliveryReceiptSerializer());
    serializers_.push_back(new DeliveryReceiptRequestSerializer());

    serializers_.push_back(new PubSubSerializer(this));
    serializers_.push_back(new PubSubEventSerializer(this));
    serializers_.push_back(new PubSubOwnerPubSubSerializer(this));
    serializers_.push_back(new PubSubErrorSerializer());

    serializers_.push_back(new ResultSetSerializer());
    serializers_.push_back(new ForwardedSerializer(this));
    serializers_.push_back(new MIXParticipantSerializer());
    serializers_.push_back(new MIXCreateSerializer());
    serializers_.push_back(new MIXRegisterNickSerializer());
    serializers_.push_back(new MIXPayloadSerializer());
    serializers_.push_back(new MIXSetNickSerializer());
    serializers_.push_back(new MIXUserPreferenceSerializer());
    serializers_.push_back(new MIXLeaveSerializer());
    serializers_.push_back(new MIXJoinSerializer());
    serializers_.push_back(new MIXDestroySerializer());
    serializers_.push_back(new MIXUpdateSubscriptionSerializer());
    serializers_.push_back(new MAMResultSerializer(this));
    serializers_.push_back(new MAMQuerySerializer());
    serializers_.push_back(new MAMFinSerializer());

    serializers_.push_back(new CarbonsDisableSerializer());
    serializers_.push_back(new CarbonsEnableSerializer());
    serializers_.push_back(new CarbonsPrivateSerializer());
    serializers_.push_back(new CarbonsReceivedSerializer(this));
    serializers_.push_back(new CarbonsSentSerializer(this));

    serializers_.push_back(new IsodeIQDelegationSerializer(this));

    for (auto serializer : serializers_) {
        addSerializer(serializer);
    }
}

FullPayloadSerializerCollection::~FullPayloadSerializerCollection() {
    for (auto serializer : serializers_) {
        removeSerializer(serializer);
        delete serializer;
    }
    serializers_.clear();
}

}
