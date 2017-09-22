#include <JXMPP/FileTransfer/IBBReceiveTransportSession.h>

#include <boost/bind.hpp>

namespace JXMPP {

IBBReceiveTransportSession::IBBReceiveTransportSession(std::shared_ptr<IBBReceiveSession> session) : session(session) {
    finishedConnection = session->onFinished.connect(boost::bind(boost::ref(onFinished), _1));
}

IBBReceiveTransportSession::~IBBReceiveTransportSession() {
}

void IBBReceiveTransportSession::start() {
    session->start();
}

void IBBReceiveTransportSession::stop() {
    session->stop();
}

}
