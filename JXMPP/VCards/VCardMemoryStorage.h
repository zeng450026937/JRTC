#ifndef JXMPP_VCARDMEMORYSTORAGE_H
#define JXMPP_VCARDMEMORYSTORAGE_H

#include <map>
#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/VCards/VCardStorage.h>

namespace JXMPP {
    class JXMPP_API VCardMemoryStorage : public VCardStorage {
        public:
            VCardMemoryStorage(CryptoProvider* crypto) : VCardStorage(crypto) {}

            virtual VCard::ref getVCard(const JID& jid) const {
                VCardMap::const_iterator i = vcards.find(jid);
                if (i != vcards.end()) {
                    return i->second;
                }
                else {
                    return VCard::ref();
                }
            }

            virtual boost::posix_time::ptime getVCardWriteTime(const JID& jid) const {
                if (vcardWriteTimes.find(jid) == vcardWriteTimes.end()) {
                    return boost::posix_time::ptime();
                }
                else {
                    return vcardWriteTimes.at(jid);
                }
            }

            virtual void setVCard(const JID& jid, VCard::ref v) {
                vcards[jid] = v;
                vcardWriteTimes[jid] = boost::posix_time::second_clock::universal_time();
            }

        private:
            typedef std::map<JID, VCard::ref> VCardMap;
            typedef std::map<JID, boost::posix_time::ptime> VCardWriteTimeMap;
            VCardMap vcards;
            VCardWriteTimeMap vcardWriteTimes;
    };
}

#endif // JXMPP_VCARDMEMORYSTORAGE_H
