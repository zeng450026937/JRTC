#include <memory>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Crypto/CryptoProvider.h>
#include <JXMPP/Crypto/PlatformCryptoProvider.h>
#include <JXMPP/TLS/Certificate.h>
#include <JXMPP/TLS/SimpleCertificate.h>

using namespace JXMPP;

class CertificateTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(CertificateTest);
        CPPUNIT_TEST(testGetSHA1Fingerprint);
        CPPUNIT_TEST_SUITE_END();

    public:
        void testGetSHA1Fingerprint() {
            SimpleCertificate::ref testling = std::make_shared<SimpleCertificate>();
            testling->setDER(createByteArray("abcdefg"));

            CPPUNIT_ASSERT_EQUAL(std::string("2f:b5:e1:34:19:fc:89:24:68:65:e7:a3:24:f4:76:ec:62:4e:87:40"), Certificate::getSHA1Fingerprint(testling, std::shared_ptr<CryptoProvider>(PlatformCryptoProvider::create()).get()));
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(CertificateTest);