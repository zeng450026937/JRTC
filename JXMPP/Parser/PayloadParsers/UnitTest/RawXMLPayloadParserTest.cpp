#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Parser/PayloadParsers/RawXMLPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/UnitTest/PayloadParserTester.h>

using namespace JXMPP;

class RawXMLPayloadParserTest : public CppUnit::TestFixture
{
        CPPUNIT_TEST_SUITE(RawXMLPayloadParserTest);
        CPPUNIT_TEST(testParse);
        CPPUNIT_TEST_SUITE_END();

    public:
        RawXMLPayloadParserTest() {}

        void testParse() {
            RawXMLPayloadParser testling;
            PayloadParserTester parser(&testling);

            std::string xml =
                "<foo foo-attr=\"foo-val\" xmlns=\"ns:foo\">"
                    "<bar bar-attr=\"bar-val\" xmlns=\"ns:bar\"/>"
                    "<baz baz-attr=\"baz-val\" xmlns=\"ns:baz\"/>"
                "</foo>";
            CPPUNIT_ASSERT(parser.parse(xml));

            RawXMLPayload* payload = dynamic_cast<RawXMLPayload*>(testling.getPayload().get());
            CPPUNIT_ASSERT_EQUAL(xml, payload->getRawXML());
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(RawXMLPayloadParserTest);
