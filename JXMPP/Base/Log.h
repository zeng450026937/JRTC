#ifndef JXMPP_LOG_H
#define JXMPP_LOG_H

#include <sstream>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API Log {
        public:
            enum Severity {
                error, warning, info, debug
            };

            Log();
            ~Log();

            std::ostringstream& getStream(
                    Severity severity,
                    const std::string& severityString,
                    const std::string& file,
                    int line,
                    const std::string& function);

            static Severity getLogLevel();
            static void setLogLevel(Severity level);

        private:
            std::ostringstream stream;
    };
}

#define JXMPP_LOG(severity) \
    if (Log::severity > Log::getLogLevel()) ; \
    else Log().getStream(Log::severity, #severity, __FILE__, __LINE__, __FUNCTION__)

#define JXMPP_LOG_ASSERT(test, severity) \
    if (Log::severity > Log::getLogLevel() || (test)) ; \
    else Log().getStream(Log::severity, #severity, __FILE__, __LINE__, __FUNCTION__) << "Assertion failed: " << #test << ". "

#endif // JXMPP_LOG_H
