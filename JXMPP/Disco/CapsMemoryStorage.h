#ifndef JXMPP_CAPSMEMORYSTORAGE_H
#define JXMPP_CAPSMEMORYSTORAGE_H

#include <map>
#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Disco/CapsStorage.h>

namespace JXMPP {
    class JXMPP_API CapsMemoryStorage : public CapsStorage {
        public:
            CapsMemoryStorage() {}

            virtual DiscoInfo::ref getDiscoInfo(const std::string& hash) const {
                CapsMap::const_iterator i = caps.find(hash);
                if (i != caps.end()) {
                    return i->second;
                }
                else {
                    return DiscoInfo::ref();
                }
            }

            virtual void setDiscoInfo(const std::string& hash, DiscoInfo::ref discoInfo) {
                caps[hash] = discoInfo;
            }

        private:
            typedef std::map<std::string, DiscoInfo::ref> CapsMap;
            CapsMap caps;
    };
}

#endif // JXMPP_CAPSMEMORYSTORAGE_H
