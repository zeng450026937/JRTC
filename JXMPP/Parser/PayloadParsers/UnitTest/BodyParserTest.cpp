#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Parser/PayloadParsers/BodyParser.h>
#include <JXMPP/Parser/PayloadParsers/UnitTest/PayloadsParserTester.h>

using namespace JXMPP;

class BodyParserTest : public CppUnit::TestFixture
{
        CPPUNIT_TEST_SUITE(BodyParserTest);
        CPPUNIT_TEST(testParse);
        CPPUNIT_TEST_SUITE_END();

    public:
        BodyParserTest() {}

        void testParse() {
            PayloadsParserTester parser;

            CPPUNIT_ASSERT(parser.parse("<body>foo<baz>bar</baz>fum</body>"));

            Body* payload = dynamic_cast<Body*>(parser.getPayload().get());
            CPPUNIT_ASSERT_EQUAL(std::string("foobarfum"), payload->getText());
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(BodyParserTest);
