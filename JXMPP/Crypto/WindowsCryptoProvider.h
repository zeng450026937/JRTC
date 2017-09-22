#ifndef JXMPP_WINDOWSCRYPTOPROVIDER_H
#define JXMPP_WINDOWSCRYPTOPROVIDER_H

#include <memory>

#include <boost/noncopyable.hpp>

#include <JXMPP/Crypto/CryptoProvider.h>

namespace JXMPP {
    class WindowsCryptoProvider : public CryptoProvider, public boost::noncopyable {
        public:
            WindowsCryptoProvider();
            virtual ~WindowsCryptoProvider();

            virtual Hash* createSHA1() override;
            virtual Hash* createMD5() override;
            virtual ByteArray getHMACSHA1(const SafeByteArray& key, const ByteArray& data) override;
            virtual ByteArray getHMACSHA1(const ByteArray& key, const ByteArray& data) override;
            virtual bool isMD5AllowedForCrypto() const override;

        private:
            struct Private;
            const std::unique_ptr<Private> p;
    };
}

#endif // JXMPP_WINDOWSCRYPTOPROVIDER_H
