#include <boost/lexical_cast.hpp>

#include <gtest/gtest.h>

#include <JXMPP/Base/ByteArray.h>

using namespace JXMPP;

TEST(ByteArrayTest, testGetData_NoData) {
    ByteArray testling;

    ASSERT_EQ(reinterpret_cast<const char*>(NULL), reinterpret_cast<const char*>(vecptr(testling)));
}

TEST(ByteArrayTest, testToString) {
    ByteArray testling(createByteArray("abcde"));

    ASSERT_EQ(std::string("abcde"), byteArrayToString(testling));
}

TEST(ByteArrayTest, testToString_NullTerminated) {
    ByteArray testling(createByteArray("abcde\0", 6));

    ASSERT_EQ(std::string("abcde"), byteArrayToString(testling));
}

TEST(ByteArrayTest, testToString_TwoNullTerminated) {
    ByteArray testling(createByteArray("abcde\0\0", 7));

    ASSERT_EQ(std::string("abcde"), byteArrayToString(testling));
}

TEST(ByteArrayTest, testToString_AllNull) {
    ByteArray testling(createByteArray("\0\0", 2));

    ASSERT_EQ(std::string(""), byteArrayToString(testling));
}
