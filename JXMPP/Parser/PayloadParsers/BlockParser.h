#ifndef JXMPP_BLOCKPARSER_H
#define JXMPP_BLOCKPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Nickname.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    template<typename BLOCK_ELEMENT>
    class JXMPP_API BlockParser : public GenericPayloadParser<BLOCK_ELEMENT> {
        public:
            BlockParser() : GenericPayloadParser<BLOCK_ELEMENT>(), level(0) {
            }

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) {
                if (level == 1 && element == "item") {
                    JID jid(attributes.getAttribute("jid"));
                    if (jid.isValid()) {
                        GenericPayloadParser<BLOCK_ELEMENT>::getPayloadInternal()->addItem(jid);
                    }
                }
                ++level;
            }

            virtual void handleEndElement(const std::string&, const std::string&) {
                --level;
            }

            virtual void handleCharacterData(const std::string&) {
            }

        private:
            int level;
    };
}

#endif // JXMPP_BLOCKPARSER_H
