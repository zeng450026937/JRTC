#ifndef JXMPP_MUCITEMPARSER_H
#define JXMPP_MUCITEMPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCItem.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>

namespace JXMPP {
    class JXMPP_API MUCItemParser  {
        public:
            static MUCItem itemFromTree(ParserElement::ref root);
        private:
            static boost::optional<MUCOccupant::Role> parseRole(const std::string& itemString);
            static boost::optional<MUCOccupant::Affiliation> parseAffiliation(const std::string& statusString);
    };
}

#endif // JXMPP_MUCITEMPARSER_H
