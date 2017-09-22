#ifndef JXMPP_COMPONENTXMLTRACER_H
#define JXMPP_COMPONENTXMLTRACER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Component/Component.h>

namespace JXMPP {
    class JXMPP_API ComponentXMLTracer {
        public:
            ComponentXMLTracer(CoreComponent* component);

        private:
            static void printData(char direction, const SafeByteArray& data);
            static void printLine(char c);
    };
}

#endif // JXMPP_COMPONENTXMLTRACER_H
