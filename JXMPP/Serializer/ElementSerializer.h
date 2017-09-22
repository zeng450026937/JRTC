#ifndef JXMPP_ELEMENTSERIALIZER_H
#define JXMPP_ELEMENTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class ElementSerializer {
        public:
            virtual ~ElementSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element) const = 0;
            virtual bool canSerialize(std::shared_ptr<ToplevelElement> element) const = 0;
    };
}

#endif // JXMPP_ELEMENTSERIALIZER_H
