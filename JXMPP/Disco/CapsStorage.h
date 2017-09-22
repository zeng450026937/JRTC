#ifndef JXMPP_CAPSSTORAGE_H
#define JXMPP_CAPSSTORAGE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoInfo.h>

namespace JXMPP {
    class JXMPP_API CapsStorage {
        public:
            virtual ~CapsStorage();

            virtual DiscoInfo::ref getDiscoInfo(const std::string&) const = 0;
            virtual void setDiscoInfo(const std::string&, DiscoInfo::ref) = 0;
    };
}

#endif // JXMPP_CAPSSTORAGE_H
