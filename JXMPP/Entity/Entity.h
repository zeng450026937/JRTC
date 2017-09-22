#ifndef JXMPP_ENTITY_H
#define JXMPP_ENTITY_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class PayloadParserFactory;
    class PayloadSerializer;
    class FullPayloadParserFactoryCollection;
    class FullPayloadSerializerCollection;
    class PayloadParserFactoryCollection;
    class PayloadSerializerCollection;

    /**
     * The base class for XMPP entities (Clients, Components).
     */
    class JXMPP_API Entity  {
        public:
            Entity();
            virtual ~Entity();

            void addPayloadParserFactory(PayloadParserFactory* payloadParserFactory);
            void removePayloadParserFactory(PayloadParserFactory* payloadParserFactory);

            void addPayloadSerializer(PayloadSerializer* payloadSerializer);
            void removePayloadSerializer(PayloadSerializer* payloadSerializer);

        protected:
            PayloadParserFactoryCollection* getPayloadParserFactories();
            PayloadSerializerCollection* getPayloadSerializers();

        private:
            FullPayloadParserFactoryCollection* payloadParserFactories;
            FullPayloadSerializerCollection* payloadSerializers;
    };
}

#endif // JXMPP_ENTITY_H
