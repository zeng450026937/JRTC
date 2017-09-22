#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Parser/PayloadParsers/PriorityParser.h>
#include <JXMPP/Parser/PayloadParsers/UnitTest/PayloadsParserTester.h>

using namespace JXMPP;

class PriorityParserTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(PriorityParserTest);
        CPPUNIT_TEST(testParse);
        CPPUNIT_TEST(testParse_Invalid);
        CPPUNIT_TEST_SUITE_END();

    public:
        void testParse() {
            PayloadsParserTester parser;

            CPPUNIT_ASSERT(parser.parse("<priority>-120</priority>"));

            std::shared_ptr<Priority> payload = std::dynamic_pointer_cast<Priority>(parser.getPayload());
            CPPUNIT_ASSERT_EQUAL(-120, payload->getPriority());
        }

        void testParse_Invalid() {
            PayloadsParserTester parser;

            CPPUNIT_ASSERT(parser.parse("<priority>invalid</priority>"));

            std::shared_ptr<Priority> payload = std::dynamic_pointer_cast<Priority>(parser.getPayload());
            CPPUNIT_ASSERT_EQUAL(0, payload->getPriority());
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(PriorityParserTest);
