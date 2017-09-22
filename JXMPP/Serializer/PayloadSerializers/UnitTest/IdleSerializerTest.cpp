/*
 * Copyright (c) 2013 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <memory>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Serializer/PayloadSerializers/IdleSerializer.h>

using namespace JXMPP;

class IdleSerializerTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(IdleSerializerTest);
        CPPUNIT_TEST(testSerialize);
        CPPUNIT_TEST_SUITE_END();

    public:
        IdleSerializerTest() {}

        void testSerialize() {
            IdleSerializer testling;
            Idle::ref idle = std::make_shared<Idle>(stringToDateTime("1969-07-21T02:56:15Z"));

            CPPUNIT_ASSERT_EQUAL(std::string("<idle xmlns='urn:xmpp:idle:1' since='1969-07-21T02:56:15Z'/>"), testling.serialize(idle));
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(IdleSerializerTest);
