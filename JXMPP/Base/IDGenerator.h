#ifndef JXMPP_IDGENERATOR_H
#define JXMPP_IDGENERATOR_H

#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API IDGenerator {
        public:
            IDGenerator();
            virtual ~IDGenerator();

            virtual std::string generateID();
    };
}

#endif // JXMPP_IDGENERATOR_H
