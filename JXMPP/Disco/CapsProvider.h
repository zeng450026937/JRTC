#ifndef JXMPP_CAPSPROVIDER_H
#define JXMPP_CAPSPROVIDER_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CapsInfo.h>
#include <JXMPP/Elements/DiscoInfo.h>

namespace JXMPP {


    class JXMPP_API CapsProvider {
        public:
            virtual ~CapsProvider() {}

            virtual DiscoInfo::ref getCaps(const std::string&) const = 0;

            boost::signals2::signal<void (const std::string&)> onCapsAvailable;
    };
}

#endif // JXMPP_CAPSPROVIDER_H
