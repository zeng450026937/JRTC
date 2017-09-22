#ifndef JXMPP_UNKNOWNELEMENTPARSER_H
#define JXMPP_UNKNOWNELEMENTPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/UnknownElement.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API UnknownElementParser : public GenericElementParser<UnknownElement> {
        public:
            UnknownElementParser() : GenericElementParser<UnknownElement>() {}
    };
}

#endif // JXMPP_UNKNOWNELEMENTPARSER_H
