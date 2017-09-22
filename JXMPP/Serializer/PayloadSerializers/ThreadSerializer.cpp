#include <JXMPP/Serializer/PayloadSerializers/ThreadSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    ThreadSerializer::ThreadSerializer() : GenericPayloadSerializer<Thread>() {
    }

    ThreadSerializer::~ThreadSerializer() {
    }

    std::string ThreadSerializer::serializePayload(std::shared_ptr<Thread> thread)  const {
        XMLElement threadNode("thread", "", thread->getText());
        if (!thread->getParent().empty()) {
            threadNode.setAttribute("parent", thread->getParent());
        }
        return threadNode.serialize();
    }
}
