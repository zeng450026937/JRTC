#ifndef JXMPP_STREAMMANAGEMENTFAILEDPARSER_H
#define JXMPP_STREAMMANAGEMENTFAILEDPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamManagementFailed.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StreamManagementFailedParser : public GenericElementParser<StreamManagementFailed> {
        public:
            StreamManagementFailedParser() : GenericElementParser<StreamManagementFailed>() {}
    };
}

#endif // JXMPP_STREAMMANAGEMENTFAILEDPARSER_H
