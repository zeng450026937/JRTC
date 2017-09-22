#ifndef JXMPP_IBBSENDTRANSPORTSESSION_H
#define JXMPP_IBBSENDTRANSPORTSESSION_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/IBBSendSession.h>
#include <JXMPP/FileTransfer/TransportSession.h>

namespace JXMPP {

class JXMPP_API IBBSendTransportSession : public TransportSession {
    public:
        IBBSendTransportSession(std::shared_ptr<IBBSendSession> session);
        virtual ~IBBSendTransportSession() override;

        virtual void start() override;
        virtual void stop() override;

    private:
        std::shared_ptr<IBBSendSession> session;
        boost::signals2::scoped_connection finishedConnection;
        boost::signals2::scoped_connection bytesSentConnection;
};

}

#endif // JXMPP_IBBSENDTRANSPORTSESSION_H
