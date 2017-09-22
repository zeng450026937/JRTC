#include <JXMPP/FileTransfer/IBBSendTransportSession.h>

#include <boost/bind.hpp>

namespace JXMPP {

IBBSendTransportSession::IBBSendTransportSession(std::shared_ptr<IBBSendSession> session) : session(session) {
    finishedConnection = session->onFinished.connect(boost::bind(boost::ref(onFinished), _1));
    bytesSentConnection = session->onBytesSent.connect(boost::bind(boost::ref(onBytesSent), _1));
}

IBBSendTransportSession::~IBBSendTransportSession() {
}

 void IBBSendTransportSession::start() {
    session->start();
}

void IBBSendTransportSession::stop() {
    session->stop();
}

}
