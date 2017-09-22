#ifndef JXMPP_FULLPAYLOADPARSERFACTORYCOLLECTION_H
#define JXMPP_FULLPAYLOADPARSERFACTORYCOLLECTION_H

#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>

namespace JXMPP {
    class JXMPP_API FullPayloadParserFactoryCollection : public PayloadParserFactoryCollection {
        public:
            FullPayloadParserFactoryCollection();
            ~FullPayloadParserFactoryCollection();

        private:
            std::vector< std::shared_ptr<PayloadParserFactory> > factories_;
            PayloadParserFactory* defaultFactory_;
    };
}

#endif // JXMPP_FULLPAYLOADPARSERFACTORYCOLLECTION_H
