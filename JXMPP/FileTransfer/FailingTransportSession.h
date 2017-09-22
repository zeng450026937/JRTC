#ifndef JXMPP_FAILINGTRANSPORTSESSION_H
#define JXMPP_FAILINGTRANSPORTSESSION_H

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/TransportSession.h>

namespace JXMPP {

class JXMPP_API FailingTransportSession : public TransportSession {
    public:
        virtual ~FailingTransportSession() override;

        virtual void start() override;
        virtual void stop() override;
};

}

#endif // JXMPP_FAILINGTRANSPORTSESSION_H
