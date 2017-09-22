#ifndef JXMPP_FORMREPORTEDREF_H
#define JXMPP_FORMREPORTEDREF_H

#include <memory>

#include <JXMPP/Base/API.h>

namespace JXMPP {

    class JXMPP_API FormReportedRef {

        public:
            typedef std::shared_ptr<FormReportedRef> ref;
    };
}

#endif // JXMPP_FORMREPORTEDREF_H
