#ifndef JXMPP_COMPRESSEDPARSER_H
#define JXMPP_COMPRESSEDPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Compressed.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API CompressedParser : public GenericElementParser<Compressed> {
        public:
            CompressedParser() : GenericElementParser<Compressed>() {}
    };
}

#endif // JXMPP_COMPRESSEDPARSER_H
