#include <JXMPP/Parser/PayloadParsers/FullPayloadParserFactoryCollection.h>

#include <JXMPP/Elements/BlockListPayload.h>
#include <JXMPP/Elements/BlockPayload.h>
#include <JXMPP/Elements/UnblockPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/GenericPayloadParserFactory2.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/BlockParser.h>
#include <JXMPP/Parser/PayloadParsers/BodyParser.h>
#include <JXMPP/Parser/PayloadParsers/BytestreamsParser.h>
#include <JXMPP/Parser/PayloadParsers/CapsInfoParser.h>
#include <JXMPP/Parser/PayloadParsers/CarbonsDisableParser.h>
#include <JXMPP/Parser/PayloadParsers/CarbonsEnableParser.h>
#include <JXMPP/Parser/PayloadParsers/CarbonsPrivateParser.h>
#include <JXMPP/Parser/PayloadParsers/CarbonsReceivedParser.h>
#include <JXMPP/Parser/PayloadParsers/CarbonsSentParser.h>
#include <JXMPP/Parser/PayloadParsers/ChatStateParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/ClientStateParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/CommandParser.h>
#include <JXMPP/Parser/PayloadParsers/DelayParser.h>
#include <JXMPP/Parser/PayloadParsers/DeliveryReceiptParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/DeliveryReceiptRequestParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/DiscoInfoParser.h>
#include <JXMPP/Parser/PayloadParsers/DiscoItemsParser.h>
#include <JXMPP/Parser/PayloadParsers/ErrorParser.h>
#include <JXMPP/Parser/PayloadParsers/ErrorParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/FormParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/ForwardedParser.h>
#include <JXMPP/Parser/PayloadParsers/IBBParser.h>
#include <JXMPP/Parser/PayloadParsers/IdleParser.h>
#include <JXMPP/Parser/PayloadParsers/InBandRegistrationPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/IsodeIQDelegationParser.h>
#include <JXMPP/Parser/PayloadParsers/JingleContentPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/JingleFileTransferDescriptionParser.h>
#include <JXMPP/Parser/PayloadParsers/JingleFileTransferDescriptionParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/JingleFileTransferFileInfoParser.h>
#include <JXMPP/Parser/PayloadParsers/JingleFileTransferHashParser.h>
#include <JXMPP/Parser/PayloadParsers/JingleIBBTransportMethodPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/JingleParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/JingleReasonParser.h>
#include <JXMPP/Parser/PayloadParsers/JingleS5BTransportMethodPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/LastParser.h>
#include <JXMPP/Parser/PayloadParsers/MAMFinParser.h>
#include <JXMPP/Parser/PayloadParsers/MAMQueryParser.h>
#include <JXMPP/Parser/PayloadParsers/MAMResultParser.h>
#include <JXMPP/Parser/PayloadParsers/MIXParticipantParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXCreateParser.h>
#include <JXMPP/Parser/PayloadParsers/MIXRegisterNickParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXSetNickParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXDestroyParser.h>
#include <JXMPP/Parser/PayloadParsers/MIXUpdateSubscriptionParser.h>
#include <JXMPP/Parser/PayloadParsers/MIXJoinParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXUserPreferenceParser.h>
#include <JXMPP/Parser/PayloadParsers/MIXLeaveParser.h>
#include <JXMPP/Parser/PayloadParsers/MUCAdminPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/MUCDestroyPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/MUCInvitationPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/MUCOwnerPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/MUCOwnerPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MUCUserPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/NicknameParser.h>
#include <JXMPP/Parser/PayloadParsers/PriorityParser.h>
#include <JXMPP/Parser/PayloadParsers/PrivateStorageParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/PubSubErrorParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubOwnerPubSubParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubParser.h>
#include <JXMPP/Parser/PayloadParsers/RawXMLPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/ReplaceParser.h>
#include <JXMPP/Parser/PayloadParsers/ResourceBindParser.h>
#include <JXMPP/Parser/PayloadParsers/ResultSetParser.h>
#include <JXMPP/Parser/PayloadParsers/RosterItemExchangeParser.h>
#include <JXMPP/Parser/PayloadParsers/RosterParser.h>
#include <JXMPP/Parser/PayloadParsers/S5BProxyRequestParser.h>
#include <JXMPP/Parser/PayloadParsers/SearchPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/SecurityLabelParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/SecurityLabelsCatalogParser.h>
#include <JXMPP/Parser/PayloadParsers/SoftwareVersionParser.h>
#include <JXMPP/Parser/PayloadParsers/StartSessionParser.h>
#include <JXMPP/Parser/PayloadParsers/StatusParser.h>
#include <JXMPP/Parser/PayloadParsers/StatusShowParser.h>
#include <JXMPP/Parser/PayloadParsers/StorageParser.h>
#include <JXMPP/Parser/PayloadParsers/StreamInitiationFileInfoParser.h>
#include <JXMPP/Parser/PayloadParsers/StreamInitiationParser.h>
#include <JXMPP/Parser/PayloadParsers/SubjectParser.h>
#include <JXMPP/Parser/PayloadParsers/ThreadParser.h>
#include <JXMPP/Parser/PayloadParsers/UserLocationParser.h>
#include <JXMPP/Parser/PayloadParsers/UserTuneParser.h>
#include <JXMPP/Parser/PayloadParsers/VCardParser.h>
#include <JXMPP/Parser/PayloadParsers/VCardUpdateParser.h>
#include <JXMPP/Parser/PayloadParsers/WhiteboardParser.h>

namespace JXMPP {

FullPayloadParserFactoryCollection::FullPayloadParserFactoryCollection() {
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<IBBParser> >("", "http://jabber.org/protocol/ibb"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<StatusShowParser> >("show"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<StatusParser> >("status"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<ReplaceParser> >("replace", "http://swift.im/protocol/replace"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<ReplaceParser> >("replace", "urn:xmpp:message-correct:0"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<LastParser> >("query", "jabber:iq:last"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<BodyParser> >("body"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<SubjectParser> >("subject"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<ThreadParser> >("thread"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<PriorityParser> >("priority"));
    factories_.push_back(std::make_shared<ErrorParserFactory>(this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<DelayParser> >("delay", "urn:xmpp:delay"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<SoftwareVersionParser> >("query", "jabber:iq:version"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<StorageParser> >("storage", "storage:bookmarks"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<RosterItemExchangeParser> >("x", "http://jabber.org/protocol/rosterx"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<RosterParser> >("query", "jabber:iq:roster"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<DiscoInfoParser> >("query", "http://jabber.org/protocol/disco#info"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<DiscoItemsParser> >("query", "http://jabber.org/protocol/disco#items"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<CapsInfoParser> >("c", "http://jabber.org/protocol/caps"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<ResourceBindParser> >("bind", "urn:ietf:params:xml:ns:xmpp-bind"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<StartSessionParser> >("session", "urn:ietf:params:xml:ns:xmpp-session"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<BlockParser<BlockPayload> > >("block", "urn:xmpp:blocking"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<BlockParser<BlockListPayload> > >("blocklist", "urn:xmpp:blocking"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<BlockParser<UnblockPayload> > >("unblock", "urn:xmpp:blocking"));
    factories_.push_back(std::make_shared<SecurityLabelParserFactory>());
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<SecurityLabelsCatalogParser> >("catalog", "urn:xmpp:sec-label:catalog:2"));
    factories_.push_back(std::make_shared<FormParserFactory>());
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<CommandParser> >("command", "http://jabber.org/protocol/commands"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<InBandRegistrationPayloadParser> >("query", "jabber:iq:register"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<SearchPayloadParser> >("query", "jabber:iq:search"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<StreamInitiationParser> >("si", "http://jabber.org/protocol/si"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<BytestreamsParser> >("query", "http://jabber.org/protocol/bytestreams"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<VCardUpdateParser> >("x", "vcard-temp:x:update"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<VCardParser> >("vCard", "vcard-temp"));
    factories_.push_back(std::make_shared<PrivateStorageParserFactory>(this));
    factories_.push_back(std::make_shared<ChatStateParserFactory>());
    factories_.push_back(std::make_shared<ClientStateParserFactory>());
    factories_.push_back(std::make_shared<MIXParticipantParserFactory>());
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MIXDestroyParser> >("destroy", "urn:xmpp:mix:0"));
    factories_.push_back(std::make_shared<MIXRegisterNickParserFactory>());
    factories_.push_back(std::make_shared<MIXSetNickParserFactory>());
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MIXCreateParser> >("create", "urn:xmpp:mix:0"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MIXUpdateSubscriptionParser> >("update-subscription", "urn:xmpp:mix:0"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MIXUserPreferenceParser> >("user-preference", "urn:xmpp:mix:0"));
    factories_.push_back(std::make_shared<MIXPayloadParserFactory>());
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MIXLeaveParser> >("leave", "urn:xmpp:mix:0"));
    factories_.push_back(std::make_shared<MUCUserPayloadParserFactory>(this));
    factories_.push_back(std::make_shared<MUCOwnerPayloadParserFactory>(this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MUCInvitationPayloadParser> >("x", "jabber:x:conference"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MUCAdminPayloadParser> >("query", "http://jabber.org/protocol/muc#admin"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MUCDestroyPayloadParser> >("destroy", "http://jabber.org/protocol/muc#user"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MUCDestroyPayloadParser> >("destroy", "http://jabber.org/protocol/muc#owner"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<NicknameParser> >("nick", "http://jabber.org/protocol/nick"));
    factories_.push_back(std::make_shared<JingleParserFactory>(this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<JingleReasonParser> >("reason", "urn:xmpp:jingle:1"));
    factories_.push_back(std::make_shared<JingleContentPayloadParserFactory>(this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<JingleIBBTransportMethodPayloadParser> >("transport", "urn:xmpp:jingle:transports:ibb:1"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<JingleS5BTransportMethodPayloadParser> >("transport", "urn:xmpp:jingle:transports:s5b:1"));
    factories_.push_back(std::make_shared<JingleFileTransferDescriptionParserFactory>(this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<StreamInitiationFileInfoParser> >("file", "http://jabber.org/protocol/si/profile/file-transfer"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<JingleFileTransferFileInfoParser> >("file", "urn:xmpp:jingle:apps:file-transfer:4"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<JingleFileTransferHashParser> >("checksum"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<S5BProxyRequestParser> >("query", "http://jabber.org/protocol/bytestreams"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<WhiteboardParser> >("wb", "http://swift.im/whiteboard"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<UserLocationParser> >("geoloc", "http://jabber.org/protocol/geoloc"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<UserTuneParser> >("tune", "http://jabber.org/protocol/tune"));
    factories_.push_back(std::make_shared<DeliveryReceiptParserFactory>());
    factories_.push_back(std::make_shared<DeliveryReceiptRequestParserFactory>());
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<IdleParser> >("idle", "urn:xmpp:idle:1"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory2<PubSubParser> >("pubsub", "http://jabber.org/protocol/pubsub", this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory2<PubSubOwnerPubSubParser> >("pubsub", "http://jabber.org/protocol/pubsub#owner", this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory2<PubSubEventParser> >("event", "http://jabber.org/protocol/pubsub#event", this));
    factories_.push_back(std::make_shared<PubSubErrorParserFactory>());
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<ResultSetParser> >("set", "http://jabber.org/protocol/rsm"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory2<ForwardedParser> >("forwarded", "urn:xmpp:forward:0", this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory2<MAMResultParser> >("result", "urn:xmpp:mam:0", this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MAMQueryParser> >("query", "urn:xmpp:mam:0"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<MAMFinParser> >("fin", "urn:xmpp:mam:0"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory2<IsodeIQDelegationParser> >("delegate", "http://isode.com/iq_delegation", this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<CarbonsEnableParser> >("enable", "urn:xmpp:carbons:2"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<CarbonsDisableParser> >("disable", "urn:xmpp:carbons:2"));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory2<CarbonsReceivedParser> >("received", "urn:xmpp:carbons:2", this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory2<CarbonsSentParser> >("sent", "urn:xmpp:carbons:2", this));
    factories_.push_back(std::make_shared<GenericPayloadParserFactory<CarbonsPrivateParser> >("private", "urn:xmpp:carbons:2"));
    factories_.push_back(std::make_shared<MIXJoinParserFactory>());

    for (auto& factory : factories_) {
        addFactory(factory.get());
    }
    defaultFactory_ = new RawXMLPayloadParserFactory();
    setDefaultFactory(defaultFactory_);
}

FullPayloadParserFactoryCollection::~FullPayloadParserFactoryCollection() {
    setDefaultFactory(nullptr);
    delete defaultFactory_;
    for (auto& factory : factories_) {
        removeFactory(factory.get());
    }
}

}
