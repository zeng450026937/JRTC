#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Parser/PayloadParsers/UnitTest/PayloadsParserTester.h>
#include <JXMPP/Parser/PayloadParsers/VCardUpdateParser.h>

using namespace JXMPP;

class VCardUpdateParserTest : public CppUnit::TestFixture
{
        CPPUNIT_TEST_SUITE(VCardUpdateParserTest);
        CPPUNIT_TEST(testParse);
        CPPUNIT_TEST_SUITE_END();

    public:
        VCardUpdateParserTest() {}

        void testParse() {
            PayloadsParserTester parser;

            CPPUNIT_ASSERT(parser.parse(
                "<x xmlns='vcard-temp:x:update'>"
                    "<photo>sha1-hash-of-image</photo>"
                "</x>"));

            VCardUpdate* payload = dynamic_cast<VCardUpdate*>(parser.getPayload().get());
            CPPUNIT_ASSERT_EQUAL(std::string("sha1-hash-of-image"), payload->getPhotoHash());
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(VCardUpdateParserTest);
