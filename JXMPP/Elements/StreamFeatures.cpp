#include <JXMPP/Elements/StreamFeatures.h>

#include <algorithm>

namespace JXMPP {

bool StreamFeatures::hasCompressionMethod(const std::string& mechanism) const {
    return std::find(compressionMethods_.begin(), compressionMethods_.end(), mechanism) != compressionMethods_.end();
}

bool StreamFeatures::hasAuthenticationMechanism(const std::string& mechanism) const {
    return std::find(authenticationMechanisms_.begin(), authenticationMechanisms_.end(), mechanism) != authenticationMechanisms_.end();
}

}
