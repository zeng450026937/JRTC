#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/LogSerializers.h>
#include <JXMPP/Base/LRUCache.h>

#include <gtest/gtest.h> // This has to go after Swiften/Base/LogSerializers.h.

using namespace JXMPP;
namespace b = boost;

TEST(LRUCacheTest, testCacheLimit) {
    LRUCache<std::string, std::string, 3> testling;

    testling.insert("A", "AA");
    testling.insert("B", "BB");
    testling.insert("C", "CC");

    ASSERT_EQ(b::optional<std::string>("AA"), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>("BB"), testling.get("B"));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));
    ASSERT_EQ(b::optional<std::string>(), testling.get("D"));

    testling.insert("D", "DD");

    ASSERT_EQ(b::optional<std::string>(), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>("BB"), testling.get("B"));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));
    ASSERT_EQ(b::optional<std::string>("DD"), testling.get("D"));
}

TEST(LRUCacheTest, testMoveRecentToFrontOnGet) {
    LRUCache<std::string, std::string, 3> testling;

    testling.insert("A", "AA");
    testling.insert("B", "BB");
    testling.insert("C", "CC");

    ASSERT_EQ(b::optional<std::string>("AA"), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>("BB"), testling.get("B"));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));
    ASSERT_EQ(b::optional<std::string>(), testling.get("D"));
    ASSERT_EQ(b::optional<std::string>("AA"), testling.get("A"));

    testling.insert("D", "DD");

    ASSERT_EQ(b::optional<std::string>("AA"), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>(), testling.get("B"));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));
    ASSERT_EQ(b::optional<std::string>("DD"), testling.get("D"));
}

TEST(LRUCacheTest, testMoveRecentToFrontOnReinsert) {
    LRUCache<std::string, std::string, 3> testling;

    testling.insert("A", "AA");
    testling.insert("B", "BB");
    testling.insert("C", "CC");

    ASSERT_EQ(b::optional<std::string>("AA"), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>("BB"), testling.get("B"));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));
    ASSERT_EQ(b::optional<std::string>(), testling.get("D"));

    testling.insert("B", "BB");

    ASSERT_EQ(b::optional<std::string>("AA"), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>("BB"), testling.get("B"));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));
    ASSERT_EQ(b::optional<std::string>(), testling.get("D"));

    testling.insert("D", "DD");

    ASSERT_EQ(b::optional<std::string>(), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>("BB"), testling.get("B"));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));
    ASSERT_EQ(b::optional<std::string>("DD"), testling.get("D"));
}

TEST(LRUCacheTest, testCacheReturnsValuesPreviouslyInserted) {
    LRUCache<std::string, std::string, 3> testling;

    testling.insert("A", "AA");
    testling.insert("B", "BB");
    testling.insert("C", "CC");

    ASSERT_EQ(b::optional<std::string>("AA"), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>("BB"), testling.get("B"));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));
}

TEST(LRUCacheTest, testCacheMissFunctionIsUsedOnCacheMiss) {
    LRUCache<std::string, std::string, 3> testling;

    testling.insert("A", "AA");
    testling.insert("B", "BB");

    ASSERT_EQ(b::optional<std::string>("AA"), testling.get("A"));
    ASSERT_EQ(b::optional<std::string>("BB"), testling.get("B"));

    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C", [](const std::string&) {
        return boost::optional<std::string>(std::string("CC"));
    }));
    ASSERT_EQ(b::optional<std::string>("CC"), testling.get("C"));

    ASSERT_EQ(b::optional<std::string>(), testling.get("D", [](const std::string&) {
        return boost::optional<std::string>();
    }));
    ASSERT_EQ(b::optional<std::string>(), testling.get("D"));
}
