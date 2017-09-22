#ifndef JXMPP_TRANSPORTSESSION_H
#define JXMPP_TRANSPORTSESSION_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/FileTransferError.h>

namespace JXMPP {
    class JXMPP_API TransportSession {
        public:
            virtual ~TransportSession();

            virtual void start() = 0;
            virtual void stop() = 0;

            boost::signals2::signal<void (size_t)> onBytesSent;
            boost::signals2::signal<void (boost::optional<FileTransferError>)> onFinished;
    };
}

#endif // JXMPP_TRANSPORTSESSION_H
