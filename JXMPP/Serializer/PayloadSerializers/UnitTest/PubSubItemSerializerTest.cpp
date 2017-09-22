#include <memory>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Elements/PubSubItem.h>
#include <JXMPP/Elements/RawXMLPayload.h>
#include <JXMPP/Serializer/PayloadSerializers/FullPayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubItemSerializer.h>

using namespace JXMPP;

class PubSubItemSerializerTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(PubSubItemSerializerTest);
        CPPUNIT_TEST(testSerialize);
        CPPUNIT_TEST(testSerializeEmptyID);
        CPPUNIT_TEST_SUITE_END();

    public:
        void testSerialize() {
            PubSubItemSerializer serializer(&serializers);

            std::shared_ptr<RawXMLPayload> payload(std::make_shared<RawXMLPayload>());
            payload->setRawXML("<payload xmlns=\"tmp\"/>");

            std::shared_ptr<PubSubItem> item(std::make_shared<PubSubItem>());
            item->addData(payload);
            item->setID("pubsub-item-1");

            std::string expectedResult =
                "<item id=\"pubsub-item-1\" xmlns=\"http://jabber.org/protocol/pubsub\">"
                    "<payload xmlns=\"tmp\"/>"
                "</item>";

            CPPUNIT_ASSERT_EQUAL(expectedResult, serializer.serialize(item));
        }

        void testSerializeEmptyID() {
            PubSubItemSerializer serializer(&serializers);

            std::shared_ptr<PubSubItem> item(std::make_shared<PubSubItem>());

            std::string expectedResult =
                "<item xmlns=\"http://jabber.org/protocol/pubsub\"/>";

            CPPUNIT_ASSERT_EQUAL(expectedResult, serializer.serialize(item));
        }

    private:
        FullPayloadSerializerCollection serializers;
};

CPPUNIT_TEST_SUITE_REGISTRATION(PubSubItemSerializerTest);
