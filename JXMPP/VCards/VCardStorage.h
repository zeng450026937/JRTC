#ifndef JXMPP_VCARDSTORAGE_H
#define JXMPP_VCARDSTORAGE_H

#include <memory>
#include <string>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/VCard.h>

namespace JXMPP {
    class JID;
    class CryptoProvider;

    class JXMPP_API VCardStorage {
        public:
            VCardStorage(CryptoProvider*);
            virtual ~VCardStorage();

            virtual VCard::ref getVCard(const JID& jid) const = 0;
            virtual boost::posix_time::ptime getVCardWriteTime(const JID& jid) const = 0;
            virtual void setVCard(const JID&, VCard::ref) = 0;

            virtual std::string getPhotoHash(const JID&) const;

        private:
            CryptoProvider* crypto;
    };
}

#endif // JXMPP_VCARDSTORAGE_H
