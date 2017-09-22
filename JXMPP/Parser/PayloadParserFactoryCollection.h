#ifndef JXMPP_PAYLOADPARSERFACTORYCOLLECTION_H
#define JXMPP_PAYLOADPARSERFACTORYCOLLECTION_H

#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/AttributeMap.h>

namespace JXMPP {
    class PayloadParserFactory;

    class JXMPP_API PayloadParserFactoryCollection {
        public:
            PayloadParserFactoryCollection();
            virtual ~PayloadParserFactoryCollection();

            void addFactory(PayloadParserFactory* factory);
            void removeFactory(PayloadParserFactory* factory);
            void setDefaultFactory(PayloadParserFactory* factory);

            PayloadParserFactory* getPayloadParserFactory(const std::string& element, const std::string& ns, const AttributeMap& attributes);

        private:
            std::vector<PayloadParserFactory*> factories_;
            PayloadParserFactory* defaultFactory_;
    };
}

#endif // JXMPP_PAYLOADPARSERFACTORYCOLLECTION_H
