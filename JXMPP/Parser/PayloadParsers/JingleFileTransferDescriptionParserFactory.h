#ifndef JXMPP_JINGLEFILETRANSFERDESCRIPTIONPARSERFACTORY_H
#define JXMPP_JINGLEFILETRANSFERDESCRIPTIONPARSERFACTORY_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/JingleFileTransferDescriptionParser.h>

namespace JXMPP {

    class PayloadParserFactoryCollection;

    class JXMPP_API JingleFileTransferDescriptionParserFactory : public PayloadParserFactory {
        public:
            JingleFileTransferDescriptionParserFactory(PayloadParserFactoryCollection* factories) : factories(factories) {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return element == "description" && ns == "urn:xmpp:jingle:apps:file-transfer:4";
            }

            virtual PayloadParser* createPayloadParser() {
                return new JingleFileTransferDescriptionParser(factories);
            }

        private:
            PayloadParserFactoryCollection* factories;

    };
}

#endif // JXMPP_JINGLEFILETRANSFERDESCRIPTIONPARSERFACTORY_H
