#ifndef JXMPP_VCARDPARSER_H
#define JXMPP_VCARDPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/VCard.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class SerializingParser;

    class JXMPP_API VCardParser : public GenericPayloadParser<VCard> {
        public:
            VCardParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            std::string getElementHierarchy() const;

        private:
            std::vector<std::string> elementStack_;
            VCard::EMailAddress currentEMailAddress_;
            VCard::Telephone currentTelephone_;
            VCard::Address currentAddress_;
            VCard::AddressLabel currentAddressLabel_;
            VCard::Organization currentOrganization_;
            SerializingParser* unknownContentParser_;
            std::string currentText_;
    };
}

#endif // JXMPP_VCARDPARSER_H
