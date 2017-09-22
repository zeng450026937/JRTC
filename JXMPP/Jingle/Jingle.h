#ifndef JXMPP_JINGLE_H
#define JXMPP_JINGLE_H

#include <vector>

#include <JXMPP/Elements/JingleContentPayload.h>

namespace JXMPP {
    namespace Jingle {
        template<typename T>
        JingleContentPayload::ref getContentWithDescription(const std::vector<JingleContentPayload::ref>& contents) {
            for (const auto& content : contents) {
                if (content->getDescription<T>()) {
                    return content;
                }
            }
            return JingleContentPayload::ref();
        }
    }
}

#endif // JXMPP_JINGLE_H
