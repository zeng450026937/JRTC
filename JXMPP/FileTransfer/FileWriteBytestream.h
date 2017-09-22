#ifndef JXMPP_FILEWRITEBYTESTREAM_H
#define JXMPP_FILEWRITEBYTESTREAM_H

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/WriteBytestream.h>

namespace JXMPP {
    class JXMPP_API FileWriteBytestream : public WriteBytestream {
        public:
            FileWriteBytestream(const boost::filesystem::path& file);
            virtual ~FileWriteBytestream();

            virtual bool write(const std::vector<unsigned char>&);
            virtual void close();

        private:
            boost::filesystem::path file;
            boost::filesystem::ofstream* stream;
    };
}

#endif // JXMPP_FILEWRITEBYTESTREAM_H
