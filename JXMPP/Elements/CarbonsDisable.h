#ifndef JXMPP_CARBONSDISABLE_H
#define JXMPP_CARBONSDISABLE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API CarbonsDisable : public Payload {
        public:
            typedef std::shared_ptr<CarbonsDisable> ref;

        public:
            virtual ~CarbonsDisable();
    };
}

#endif // JXMPP_CARBONSDISABLE_H
