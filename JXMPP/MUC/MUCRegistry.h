#ifndef JXMPP_MUCREGISTRY_H
#define JXMPP_MUCREGISTRY_H

#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JID;

    class JXMPP_API MUCRegistry {
        public:
            virtual ~MUCRegistry();

            bool isMUC(const JID& j) const;
            void addMUC(const JID& j);
            void removeMUC(const JID& j);

        private:
            std::vector<JID> mucs;
    };
}

#endif // JXMPP_MUCREGISTRY_H
