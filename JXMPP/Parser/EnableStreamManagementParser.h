#ifndef JXMPP_ENABLESTREAMMANAGEMENTPARSER_H
#define JXMPP_ENABLESTREAMMANAGEMENTPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/EnableStreamManagement.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API EnableStreamManagementParser : public GenericElementParser<EnableStreamManagement> {
        public:
            EnableStreamManagementParser() : GenericElementParser<EnableStreamManagement>() {}
    };
}

#endif // JXMPP_ENABLESTREAMMANAGEMENTPARSER_H
