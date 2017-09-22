#ifndef JXMPP_IQHANDLER_H
#define JXMPP_IQHANDLER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IQ.h>

namespace JXMPP {
    class JXMPP_API IQHandler {
        public:
            virtual ~IQHandler();

            virtual bool handleIQ(std::shared_ptr<IQ>) = 0;
    };
}

#endif // JXMPP_IQHANDLER_H
