#include <memory>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/SoftwareVersion.h>

using namespace JXMPP;

class IQTest : public CppUnit::TestFixture
{
        CPPUNIT_TEST_SUITE(IQTest);
        CPPUNIT_TEST(testCreateResult);
        CPPUNIT_TEST(testCreateResult_WithoutPayload);
        CPPUNIT_TEST(testCreateError);
        CPPUNIT_TEST_SUITE_END();

    public:
        IQTest() {}

        void testCreateResult() {
            std::shared_ptr<Payload> payload(new SoftwareVersion("myclient"));
            std::shared_ptr<IQ> iq(IQ::createResult(JID("foo@bar/fum"), "myid", payload));

            CPPUNIT_ASSERT_EQUAL(JID("foo@bar/fum"), iq->getTo());
            CPPUNIT_ASSERT_EQUAL(std::string("myid"), iq->getID());
            CPPUNIT_ASSERT(iq->getPayload<SoftwareVersion>());
            CPPUNIT_ASSERT(payload == iq->getPayload<SoftwareVersion>());
        }

        void testCreateResult_WithoutPayload() {
            std::shared_ptr<IQ> iq(IQ::createResult(JID("foo@bar/fum"), "myid"));

            CPPUNIT_ASSERT_EQUAL(JID("foo@bar/fum"), iq->getTo());
            CPPUNIT_ASSERT_EQUAL(std::string("myid"), iq->getID());
            CPPUNIT_ASSERT(!iq->getPayload<SoftwareVersion>());
        }

        void testCreateError() {
            std::shared_ptr<IQ> iq(IQ::createError(JID("foo@bar/fum"), "myid", ErrorPayload::BadRequest, ErrorPayload::Modify));

            CPPUNIT_ASSERT_EQUAL(JID("foo@bar/fum"), iq->getTo());
            CPPUNIT_ASSERT_EQUAL(std::string("myid"), iq->getID());
            std::shared_ptr<ErrorPayload> error(iq->getPayload<ErrorPayload>());
            CPPUNIT_ASSERT(error);
            CPPUNIT_ASSERT_EQUAL(ErrorPayload::BadRequest, error->getCondition());
            CPPUNIT_ASSERT_EQUAL(ErrorPayload::Modify, error->getType());
        }

};

CPPUNIT_TEST_SUITE_REGISTRATION(IQTest);
