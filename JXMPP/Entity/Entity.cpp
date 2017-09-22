#include <JXMPP/Entity/Entity.h>

#include <JXMPP/Parser/PayloadParsers/FullPayloadParserFactoryCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/FullPayloadSerializerCollection.h>

namespace JXMPP {

Entity::Entity() {
    payloadParserFactories = new FullPayloadParserFactoryCollection();
    payloadSerializers = new FullPayloadSerializerCollection();
}

Entity::~Entity() {
    delete payloadSerializers;
    delete payloadParserFactories;
}


void Entity::addPayloadParserFactory(PayloadParserFactory* payloadParserFactory) {
    payloadParserFactories->addFactory(payloadParserFactory);
}

void Entity::removePayloadParserFactory(PayloadParserFactory* payloadParserFactory) {
    payloadParserFactories->removeFactory(payloadParserFactory);
}

void Entity::addPayloadSerializer(PayloadSerializer* payloadSerializer) {
    payloadSerializers->addSerializer(payloadSerializer);
}

void Entity::removePayloadSerializer(PayloadSerializer* payloadSerializer) {
    payloadSerializers->removeSerializer(payloadSerializer);
}

PayloadParserFactoryCollection* Entity::getPayloadParserFactories() {
    return payloadParserFactories;
}

PayloadSerializerCollection* Entity::getPayloadSerializers() {
    return payloadSerializers;
}

}
