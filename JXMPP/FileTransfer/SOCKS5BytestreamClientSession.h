#ifndef JXMPP_SOCKS5BYTESTREAMCLIENTSESSION_H
#define JXMPP_SOCKS5BYTESTREAMCLIENTSESSION_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/FileTransfer/FileTransferError.h>
#include <JXMPP/FileTransfer/ReadBytestream.h>
#include <JXMPP/FileTransfer/WriteBytestream.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/Network/HostAddressPort.h>
#include <JXMPP/Network/Timer.h>

namespace JXMPP {

class Connection;
class TimerFactory;

/**
 * A session which has been connected to a SOCKS5 server (requester).
 *
 */
class JXMPP_API SOCKS5BytestreamClientSession {
public:
    enum State {
        Initial,
        Hello,
        Authenticating,
        Ready,
        Writing,
        Reading,
        Finished
    };

public:
    typedef std::shared_ptr<SOCKS5BytestreamClientSession> ref;

public:
    SOCKS5BytestreamClientSession(
            std::shared_ptr<Connection> connection,
            const HostAddressPort&,
            const std::string&,
            TimerFactory*);
    ~SOCKS5BytestreamClientSession();

    void start();
    void stop();

    void startReceiving(std::shared_ptr<WriteBytestream>);
    void startSending(std::shared_ptr<ReadBytestream>);

    HostAddressPort getAddressPort() const;

    boost::signals2::signal<void (bool /*error*/)> onSessionReady;

    boost::signals2::signal<void (boost::optional<FileTransferError>)> onFinished;
    boost::signals2::signal<void (size_t)> onBytesSent;
    // boost::signals2::signal<void (size_t)> onBytesReceived;

private:
    void process();
    void hello();
    void authenticate();

    void handleConnectFinished(bool error);
    void handleDataRead(std::shared_ptr<SafeByteArray>);
    void handleDisconnected(const boost::optional<Connection::Error>&);
    void handleWeFailedTimeout();

    void finish(bool error);
    void sendData();
    void closeConnection();

private:
    std::shared_ptr<Connection> connection;
    HostAddressPort addressPort;
    std::string destination; // hexify(SHA1(sessionID + requester + target))

    State state;

    ByteArray unprocessedData;
    ByteArray authenticateAddress;

    int chunkSize;
    std::shared_ptr<WriteBytestream> writeBytestream;
    std::shared_ptr<ReadBytestream> readBytestream;

    Timer::ref weFailedTimeout;

    boost::signals2::scoped_connection connectFinishedConnection;
    boost::signals2::scoped_connection dataWrittenConnection;
    boost::signals2::scoped_connection dataReadConnection;
    boost::signals2::scoped_connection disconnectedConnection;
};

}

#endif // JXMPP_SOCKS5BYTESTREAMCLIENTSESSION_H
