#ifndef JXMPP_GENERICELEMENTSERIALIZER_H
#define JXMPP_GENERICELEMENTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Serializer/ElementSerializer.h>

namespace JXMPP {
    template<typename T>
    class JXMPP_API GenericElementSerializer : public ElementSerializer {
        public:
            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element) const = 0;

            virtual bool canSerialize(std::shared_ptr<ToplevelElement> element) const {
                return !!std::dynamic_pointer_cast<T>(element);
            }
    };
}

#endif // JXMPP_GENERICELEMENTSERIALIZER_H
