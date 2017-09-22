#ifndef JXMPP_COMMANDSERIALIZER_H
#define JXMPP_COMMANDSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Command.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API CommandSerializer : public GenericPayloadSerializer<Command> {
        public:
            CommandSerializer();

            virtual std::string serializePayload(std::shared_ptr<Command>)  const;

        private:
            std::string actionToString(Command::Action action) const;
    };
}

#endif // JXMPP_COMMANDSERIALIZER_H
