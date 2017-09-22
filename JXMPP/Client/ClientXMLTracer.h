#ifndef JXMPP_CLIENTXMLTRACER_H
#define JXMPP_CLIENTXMLTRACER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Client/CoreClient.h>
#include <JXMPP/Client/XMLBeautifier.h>

namespace JXMPP {
    class JXMPP_API ClientXMLTracer {
        public:
            ClientXMLTracer(CoreClient* client, bool bosh = false);

        private:
            void printData(char direction, const SafeByteArray& data);
            void printLine(char c);

        private:
            std::unique_ptr<XMLBeautifier> beautifier_;
            bool bosh_;
            boost::signals2::scoped_connection onDataReadConnection_;
            boost::signals2::scoped_connection onDataWrittenConnection_;
    };
}

#endif // JXMPP_CLIENTXMLTRACER_H
