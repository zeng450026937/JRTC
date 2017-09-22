#ifndef JXMPP_BLOCKSERIALIZER_H
#define JXMPP_BLOCKSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    template<typename BLOCK_ELEMENT>
    class JXMPP_API BlockSerializer : public GenericPayloadSerializer<BLOCK_ELEMENT> {
        public:
            BlockSerializer(std::string tag) : GenericPayloadSerializer<BLOCK_ELEMENT>(), tag(tag) {
            }

            virtual std::string serializePayload(std::shared_ptr<BLOCK_ELEMENT> payload)    const {
                XMLElement element(tag, "urn:xmpp:blocking");
                const std::vector<JID>& items = payload->getItems();
                for (const auto& i : items) {
                    std::shared_ptr<XMLElement> item = std::make_shared<XMLElement>("item");
                    item->setAttribute("jid", i);
                    element.addNode(item);
                }
                return element.serialize();
            }

        private:
            std::string tag;
    };
}

#endif // JXMPP_BLOCKSERIALIZER_H
