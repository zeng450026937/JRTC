#ifndef JXMPP_SIMPLEIDGENERATOR_H
#define JXMPP_SIMPLEIDGENERATOR_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/IDGenerator.h>

namespace JXMPP {

    /**
     * @brief The SimpleIDGenerator class implements a IDGenerator generating consecutive ID strings from
     * the lower case latin alphabet.
     */

    class JXMPP_API SimpleIDGenerator : public IDGenerator {
        public:
            SimpleIDGenerator();
            ~SimpleIDGenerator() override;

            std::string generateID() override;

        private:
            std::string currentID;
    };
}

#endif // JXMPP_SIMPLEIDGENERATOR_H
