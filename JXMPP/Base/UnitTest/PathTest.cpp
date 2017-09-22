#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Base/Path.h>
#include <JXMPP/Base/Platform.h>

using namespace JXMPP;

class PathTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(PathTest);
        CPPUNIT_TEST(testStringToPath);
        CPPUNIT_TEST(testPathToString);
        CPPUNIT_TEST_SUITE_END();

    public:
        void testStringToPath() {
#ifdef JXMPP_PLATFORM_WINDOWS
            CPPUNIT_ASSERT(std::wstring(L"tron\xe7on") == stringToPath("tron\xc3\xa7on").native());
#else
            CPPUNIT_ASSERT_EQUAL(std::string("tron\xc3\xa7on"), stringToPath("tron\xc3\xa7on").native());
#endif
        }

        void testPathToString() {
            CPPUNIT_ASSERT_EQUAL(std::string("tron\xc3\xa7on"), pathToString(stringToPath("tron\xc3\xa7on")));
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(PathTest);
