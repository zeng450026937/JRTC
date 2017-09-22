#include <JXMPP/FileTransfer/SOCKS5BytestreamRegistry.h>

#include <memory>

#include <JXMPP/Base/Algorithm.h>
#include <JXMPP/Base/Log.h>

namespace JXMPP {

SOCKS5BytestreamRegistry::SOCKS5BytestreamRegistry() {
}

void SOCKS5BytestreamRegistry::setHasBytestream(const std::string& destination, bool b) {
    if (b) {
        availableBytestreams.insert(destination);
    }
    else {
        availableBytestreams.erase(destination);
    }
}

bool SOCKS5BytestreamRegistry::hasBytestream(const std::string& destination) const {
    return availableBytestreams.find(destination) != availableBytestreams.end();
}

std::string SOCKS5BytestreamRegistry::generateSessionID() {
    return idGenerator.generateID();
}

}
