#ifndef JXMPP_FILEREADBYTESTREAM_H
#define JXMPP_FILEREADBYTESTREAM_H

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/ReadBytestream.h>

namespace JXMPP {
    class JXMPP_API FileReadBytestream : public ReadBytestream {
        public:
            FileReadBytestream(const boost::filesystem::path& file);
            virtual ~FileReadBytestream();

            virtual std::shared_ptr< std::vector<unsigned char> > read(size_t size);
            virtual bool isFinished() const;

        private:
            boost::filesystem::path file;
            boost::filesystem::ifstream* stream;
    };
}

#endif // JXMPP_FILEREADBYTESTREAM_H
