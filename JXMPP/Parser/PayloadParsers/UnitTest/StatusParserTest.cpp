#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Parser/PayloadParsers/StatusParser.h>
#include <JXMPP/Parser/PayloadParsers/UnitTest/PayloadsParserTester.h>

using namespace JXMPP;

class StatusParserTest : public CppUnit::TestFixture
{
        CPPUNIT_TEST_SUITE(StatusParserTest);
        CPPUNIT_TEST(testParse);
        CPPUNIT_TEST_SUITE_END();

    public:
        StatusParserTest() {}

        void testParse() {
            PayloadsParserTester parser;

            CPPUNIT_ASSERT(parser.parse("<status>foo<baz>bar</baz>fum</status>"));

            Status* payload = dynamic_cast<Status*>(parser.getPayload().get());
            CPPUNIT_ASSERT_EQUAL(std::string("foobarfum"), payload->getText());
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(StatusParserTest);
