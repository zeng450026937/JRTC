#include <QA/Checker/IO.h>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Elements/StreamFeatures.h>
#include <JXMPP/Serializer/StreamFeaturesSerializer.h>

using namespace JXMPP;

class StreamFeaturesSerializerTest : public CppUnit::TestFixture
{
        CPPUNIT_TEST_SUITE(StreamFeaturesSerializerTest);
        CPPUNIT_TEST(testSerialize);
        CPPUNIT_TEST_SUITE_END();

    public:
        StreamFeaturesSerializerTest() {}

        void testSerialize() {
            StreamFeaturesSerializer testling;
            std::shared_ptr<StreamFeatures> streamFeatures(new StreamFeatures());
            streamFeatures->setHasStartTLS();
            streamFeatures->addCompressionMethod("zlib");
            streamFeatures->addCompressionMethod("lzw");
            streamFeatures->addAuthenticationMechanism("DIGEST-MD5");
            streamFeatures->addAuthenticationMechanism("PLAIN");
            streamFeatures->setHasResourceBind();
            streamFeatures->setHasSession();
            streamFeatures->setHasStreamManagement();
            streamFeatures->setHasRosterVersioning();

            CPPUNIT_ASSERT_EQUAL(createSafeByteArray(
                "<stream:features>"
                    "<starttls xmlns=\"urn:ietf:params:xml:ns:xmpp-tls\"/>"
                    "<compression xmlns=\"http://jabber.org/features/compress\">"
                        "<method>zlib</method>"
                        "<method>lzw</method>"
                    "</compression>"
                    "<mechanisms xmlns=\"urn:ietf:params:xml:ns:xmpp-sasl\">"
                        "<mechanism>DIGEST-MD5</mechanism>"
                        "<mechanism>PLAIN</mechanism>"
                    "</mechanisms>"
                    "<bind xmlns=\"urn:ietf:params:xml:ns:xmpp-bind\"/>"
                    "<session xmlns=\"urn:ietf:params:xml:ns:xmpp-session\"/>"
                    "<sm xmlns=\"urn:xmpp:sm:2\"/>"
                    "<ver xmlns=\"urn:xmpp:features:rosterver\"/>"
                "</stream:features>"), testling.serialize(streamFeatures));
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(StreamFeaturesSerializerTest);
