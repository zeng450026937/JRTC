#ifndef JXMPP_IBBRECEIVETRANSPORTSESSION_H
#define JXMPP_IBBRECEIVETRANSPORTSESSION_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/IBBReceiveSession.h>
#include <JXMPP/FileTransfer/TransportSession.h>

namespace JXMPP {

class JXMPP_API IBBReceiveTransportSession : public TransportSession {
    public:
        IBBReceiveTransportSession(std::shared_ptr<IBBReceiveSession> session);
        virtual ~IBBReceiveTransportSession() override;

        virtual void start() override;
        virtual void stop() override;

    private:
        std::shared_ptr<IBBReceiveSession> session;
        boost::signals2::scoped_connection finishedConnection;
        boost::signals2::scoped_connection bytesSentConnection;
};

}

#endif // JXMPP_IBBRECEIVETRANSPORTSESSION_H
