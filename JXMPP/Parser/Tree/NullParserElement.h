#ifndef JXMPP_NULLPARSERELEMENT_H
#define JXMPP_NULLPARSERELEMENT_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/Tree/ParserElement.h>

namespace JXMPP {
    class JXMPP_API NullParserElement : public ParserElement {
        public:
            NullParserElement() : ParserElement("", "", AttributeMap()) {}

            virtual operator bool() { return false; }

            static std::shared_ptr<NullParserElement> element;
    };
}

#endif // JXMPP_NULLPARSERELEMENT_H
