#ifndef JXMPP_MUCMANAGER_H
#define JXMPP_MUCMANAGER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/MUC/MUC.h>

namespace JXMPP {
    class IQRouter;
    class StanzaChannel;
    class DirectedPresenceSender;
    class MUCRegistry;

    class JXMPP_API MUCManager {
        public:
            MUCManager(StanzaChannel* stanzaChannel, IQRouter* iqRouter, DirectedPresenceSender* presenceSender, MUCRegistry* mucRegistry);

            MUC::ref createMUC(const JID&);

        private:
            StanzaChannel* stanzaChannel;
            IQRouter* iqRouter;
            DirectedPresenceSender* presenceSender;
            MUCRegistry* mucRegistry;
    };
}

#endif // JXMPP_MUCMANAGER_H
