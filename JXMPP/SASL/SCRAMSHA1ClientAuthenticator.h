#ifndef JXMPP_SCRAMSHA1CLIENTAUTHENTICATOR_H
#define JXMPP_SCRAMSHA1CLIENTAUTHENTICATOR_H

#include <map>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/SASL/ClientAuthenticator.h>

namespace JXMPP {
    class IDNConverter;
    class CryptoProvider;

    class JXMPP_API SCRAMSHA1ClientAuthenticator : public ClientAuthenticator {
        public:
            SCRAMSHA1ClientAuthenticator(const std::string& nonce, bool useChannelBinding, IDNConverter*, CryptoProvider*);

            void setTLSChannelBindingData(const ByteArray& channelBindingData);

            virtual boost::optional<SafeByteArray> getResponse() const;
            virtual bool setChallenge(const boost::optional<ByteArray>&);

        private:
            ByteArray getInitialBareClientMessage() const;
            ByteArray getGS2Header() const;
            ByteArray getFinalMessageWithoutProof() const;

            static std::map<char, std::string> parseMap(const std::string&);

        private:
            enum Step {
                Initial,
                Proof,
                Final
            } step;
            std::string clientnonce;
            ByteArray initialServerMessage;
            ByteArray serverNonce;
            ByteArray authMessage;
            ByteArray saltedPassword;
            ByteArray serverSignature;
            bool useChannelBinding;
            IDNConverter* idnConverter;
            CryptoProvider* crypto;
            boost::optional<ByteArray> tlsChannelBindingData;
    };
}

#endif // JXMPP_SCRAMSHA1CLIENTAUTHENTICATOR_H
