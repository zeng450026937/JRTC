#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Elements/PrivateStorage.h>
#include <JXMPP/Elements/Storage.h>
#include <JXMPP/Serializer/PayloadSerializers/UnitTest/PayloadsSerializer.h>

using namespace JXMPP;

class PrivateStorageSerializerTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(PrivateStorageSerializerTest);
        CPPUNIT_TEST(testSerialize);
        CPPUNIT_TEST_SUITE_END();

    public:
        PrivateStorageSerializerTest() {}

        void testSerialize() {
            PayloadsSerializer serializer;

            std::shared_ptr<PrivateStorage> privateStorage(new PrivateStorage());
            std::shared_ptr<Storage> storage(new Storage());
            Storage::Room room;
            room.name = "JXMPP";
            room.jid = JID("swift@rooms.swift.im");
            room.nick = "Alice";
            storage->addRoom(room);
            privateStorage->setPayload(storage);

            CPPUNIT_ASSERT_EQUAL(std::string(
                "<query xmlns=\"jabber:iq:private\">"
                    "<storage xmlns=\"storage:bookmarks\">"
                        "<conference "
                                "autojoin=\"0\" "
                                "jid=\"swift@rooms.swift.im\" "
                                "name=\"Swift\">"
                            "<nick>Alice</nick>"
                        "</conference>"
                    "</storage>"
                "</query>"), serializer.serialize(privateStorage));
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(PrivateStorageSerializerTest);
