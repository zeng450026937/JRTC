/*
 * Copyright (c) 2013 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Elements/Idle.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/Parser/PayloadParsers/UnitTest/PayloadsParserTester.h>

using namespace JXMPP;

class IdleParserTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(IdleParserTest);
        CPPUNIT_TEST(testParse_XepWhatever_Example1);
        CPPUNIT_TEST_SUITE_END();

    public:
        void testParse_XepWhatever_Example1() {
            PayloadsParserTester parser;
            CPPUNIT_ASSERT(parser.parse(
                "<presence from='juliet@capulet.com/balcony'>\n"
                    "<show>away</show>\n"
                    "<idle xmlns='urn:xmpp:idle:1' since='1969-07-21T02:56:15Z'/>\n"
                "</presence>\n"
            ));

            Presence::ref presence = parser.getPayload<Presence>();
            CPPUNIT_ASSERT(presence);
            Idle::ref idle = presence->getPayload<Idle>();
            CPPUNIT_ASSERT(idle);
            CPPUNIT_ASSERT(stringToDateTime("1969-07-21T02:56:15Z") == idle->getSince());
        }
};
