#ifndef JXMPP_SECURITYLABELPARSERFACTORY_H
#define JXMPP_SECURITYLABELPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/SecurityLabelParser.h>

namespace JXMPP {
    class JXMPP_API SecurityLabelParserFactory : public GenericPayloadParserFactory<SecurityLabelParser> {
        public:
            SecurityLabelParserFactory() : GenericPayloadParserFactory<SecurityLabelParser>("securitylabel", "urn:xmpp:sec-label:0") {}
    };
}

#endif // JXMPP_SECURITYLABELPARSERFACTORY_H
