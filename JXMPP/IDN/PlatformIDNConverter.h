#ifndef JXMPP_PLATFORMIDNCONVERTER_H
#define JXMPP_PLATFORMIDNCONVERTER_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class IDNConverter;

    namespace PlatformIDNConverter {
        JXMPP_API IDNConverter* create();
    }
}

#endif // JXMPP_PLATFORMIDNCONVERTER_H
