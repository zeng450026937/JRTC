#ifndef JXMPP_SOCKS5BYTESTREAMREGISTRY_H
#define JXMPP_SOCKS5BYTESTREAMREGISTRY_H

#include <map>
#include <set>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/IDGenerator.h>

namespace JXMPP {
    class JXMPP_API SOCKS5BytestreamRegistry {
        public:
            SOCKS5BytestreamRegistry();

            void setHasBytestream(const std::string& destination, bool);
            bool hasBytestream(const std::string& destination) const;

            /**
             * Generate a new session ID to use for new S5B streams.
             */
            std::string generateSessionID();

        private:
            std::set<std::string> availableBytestreams;
            IDGenerator idGenerator;
    };
}

#endif // JXMPP_SOCKS5BYTESTREAMREGISTRY_H
