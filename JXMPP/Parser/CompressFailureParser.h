#ifndef JXMPP_COMPRESSFAILUREPARSER_H
#define JXMPP_COMPRESSFAILUREPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CompressFailure.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API CompressFailureParser : public GenericElementParser<CompressFailure> {
        public:
            CompressFailureParser() : GenericElementParser<CompressFailure>() {}
    };
}

#endif // JXMPP_COMPRESSFAILUREPARSER_H
