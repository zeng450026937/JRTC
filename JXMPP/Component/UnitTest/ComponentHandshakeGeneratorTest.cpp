#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Component/ComponentHandshakeGenerator.h>
#include <JXMPP/Crypto/CryptoProvider.h>
#include <JXMPP/Crypto/PlatformCryptoProvider.h>

using namespace JXMPP;

class ComponentHandshakeGeneratorTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(ComponentHandshakeGeneratorTest);
        CPPUNIT_TEST(testGetHandshake);
        CPPUNIT_TEST(testGetHandshake_SpecialChars);
        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() {
            crypto = std::shared_ptr<CryptoProvider>(PlatformCryptoProvider::create());
        }

        void testGetHandshake() {
            std::string result = ComponentHandshakeGenerator::getHandshake("myid", "mysecret", crypto.get());
            CPPUNIT_ASSERT_EQUAL(std::string("4011cd31f9b99ac089a0cd7ce297da7323fa2525"), result);
        }

        void testGetHandshake_SpecialChars() {
            std::string result = ComponentHandshakeGenerator::getHandshake("&<", ">'\"", crypto.get());
            CPPUNIT_ASSERT_EQUAL(std::string("33631b3e0aaeb2a11c4994c917919324028873fe"), result);
        }

    private:
        std::shared_ptr<CryptoProvider> crypto;
};

CPPUNIT_TEST_SUITE_REGISTRATION(ComponentHandshakeGeneratorTest);
