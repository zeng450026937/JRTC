#include <JXMPP/Component/ComponentHandshakeGenerator.h>

#include <JXMPP/Base/String.h>
#include <JXMPP/Crypto/CryptoProvider.h>
#include <JXMPP/StringCodecs/Hexify.h>

namespace JXMPP {

std::string ComponentHandshakeGenerator::getHandshake(const std::string& streamID, const std::string& secret, CryptoProvider* crypto) {
    std::string concatenatedString = streamID + secret;
    String::replaceAll(concatenatedString, '&', "&amp;");
    String::replaceAll(concatenatedString, '<', "&lt;");
    String::replaceAll(concatenatedString, '>', "&gt;");
    String::replaceAll(concatenatedString, '\'', "&apos;");
    String::replaceAll(concatenatedString, '"', "&quot;");
    return Hexify::hexify(crypto->getSHA1Hash(createByteArray(concatenatedString)));
}

}
