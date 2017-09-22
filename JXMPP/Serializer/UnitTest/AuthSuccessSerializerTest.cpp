#include <QA/Checker/IO.h>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Elements/AuthSuccess.h>
#include <JXMPP/Serializer/AuthSuccessSerializer.h>

using namespace JXMPP;

class AuthSuccessSerializerTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(AuthSuccessSerializerTest);
        CPPUNIT_TEST(testSerialize);
        CPPUNIT_TEST(testSerialize_NoMessage);
        CPPUNIT_TEST(testSerialize_EmptyMessage);
        CPPUNIT_TEST_SUITE_END();

    public:
        void testSerialize() {
            AuthSuccessSerializer testling;
            std::shared_ptr<AuthSuccess> authSuccess(new AuthSuccess());
            authSuccess->setValue(createByteArray("foo"));

            CPPUNIT_ASSERT_EQUAL(createSafeByteArray(
                "<success xmlns=\"urn:ietf:params:xml:ns:xmpp-sasl\">"
                    "Zm9v"
                "</success>"), testling.serialize(authSuccess));
        }

        void testSerialize_NoMessage() {
            AuthSuccessSerializer testling;
            std::shared_ptr<AuthSuccess> authSuccess(new AuthSuccess());

            CPPUNIT_ASSERT_EQUAL(createSafeByteArray(
                "<success xmlns=\"urn:ietf:params:xml:ns:xmpp-sasl\">"
                "</success>"), testling.serialize(authSuccess));
        }

        void testSerialize_EmptyMessage() {
            AuthSuccessSerializer testling;
            std::shared_ptr<AuthSuccess> authSuccess(new AuthSuccess());
            authSuccess->setValue(std::vector<unsigned char>());

            CPPUNIT_ASSERT_EQUAL(createSafeByteArray(
                "<success xmlns=\"urn:ietf:params:xml:ns:xmpp-sasl\">"
                    "="
                "</success>"), testling.serialize(authSuccess));
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(AuthSuccessSerializerTest);
