/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <gtest/gtest.h>

#include <JXMPP/Serializer/PayloadSerializers/MIXRegisterNickSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/FullPayloadSerializerCollection.h>

using namespace JXMPP;

TEST(MIXRegisterNickSerializerTest, testSerializeNick) {
    MIXRegisterNickSerializer testling;

    auto mix = std::shared_ptr<MIXRegisterNick>(new MIXRegisterNick());
    mix->setNick(std::string("thirdwitch"));

    std::string expectedResult = "<register xmlns=\"urn:xmpp:mix:0\"><nick>thirdwitch</nick></register>";
    ASSERT_EQ(expectedResult, testling.serialize(mix));
}
