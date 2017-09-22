#ifndef JXMPP_VCARDUPDATE_H
#define JXMPP_VCARDUPDATE_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API VCardUpdate : public Payload {
        public:
            VCardUpdate(const std::string& photoHash = "") : photoHash_(photoHash) {}

            void setPhotoHash(const std::string& photoHash) { photoHash_ = photoHash; }
            const std::string& getPhotoHash() const { return photoHash_; }

        private:
            std::string photoHash_;
    };
}

#endif // JXMPP_VCARDUPDATE_H
