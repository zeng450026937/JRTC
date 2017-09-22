#ifndef JXMPP_FILETRANSFERMANAGER_H
#define JXMPP_FILETRANSFERMANAGER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <string>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/FileTransfer/FileTransferOptions.h>
#include <JXMPP/FileTransfer/IncomingFileTransfer.h>
#include <JXMPP/FileTransfer/OutgoingFileTransfer.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class ReadBytestream;

    class JXMPP_API FileTransferManager {
        public:
            virtual ~FileTransferManager();

            virtual OutgoingFileTransfer::ref createOutgoingFileTransfer(
                    const JID& to,
                    const boost::filesystem::path& filepath,
                    const std::string& description,
                    std::shared_ptr<ReadBytestream> bytestream,
                    const FileTransferOptions& = FileTransferOptions()) = 0;
            virtual OutgoingFileTransfer::ref createOutgoingFileTransfer(
                    const JID& to,
                    const std::string& filename,
                    const std::string& description,
                    const boost::uintmax_t sizeInBytes,
                    const boost::posix_time::ptime& lastModified,
                    std::shared_ptr<ReadBytestream> bytestream,
                    const FileTransferOptions& = FileTransferOptions()) = 0;

            boost::signals2::signal<void (IncomingFileTransfer::ref)> onIncomingFileTransfer;
    };
}

#endif // JXMPP_FILETRANSFERMANAGER_H
