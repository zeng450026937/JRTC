#ifndef JXMPP_SUBJECTSERIALIZER_H
#define JXMPP_SUBJECTSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Subject.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {
    class JXMPP_API SubjectSerializer : public GenericPayloadSerializer<Subject> {
        public:
            SubjectSerializer() : GenericPayloadSerializer<Subject>() {}

            virtual std::string serializePayload(std::shared_ptr<Subject> subject)  const {
                XMLTextNode textNode(subject->getText());
                return "<subject>" + textNode.serialize() + "</subject>";
            }
    };
}

#endif // JXMPP_SUBJECTSERIALIZER_H
