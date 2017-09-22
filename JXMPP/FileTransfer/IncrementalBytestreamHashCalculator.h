#ifndef JXMPP_INCREMENTALBYTESTREAMHASHCALCULATOR_H
#define JXMPP_INCREMENTALBYTESTREAMHASHCALCULATOR_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class Hash;
    class CryptoProvider;

    class IncrementalBytestreamHashCalculator {
    public:
        IncrementalBytestreamHashCalculator(bool doMD5, bool doSHA1, CryptoProvider* crypto);
        ~IncrementalBytestreamHashCalculator();

        void feedData(const ByteArray& data);
        //void feedData(const SafeByteArray& data);

        ByteArray getSHA1Hash();
        ByteArray getMD5Hash();

        std::string getSHA1String();
        std::string getMD5String();

    private:
        Hash* md5Hasher;
        Hash* sha1Hasher;
        boost::optional<ByteArray> md5Hash;
        boost::optional<ByteArray> sha1Hash;
    };

}

#endif // JXMPP_INCREMENTALBYTESTREAMHASHCALCULATOR_H
