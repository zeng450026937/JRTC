#ifndef JXMPP_BYTEARRAYWRITEBYTESTREAM_H
#define JXMPP_BYTEARRAYWRITEBYTESTREAM_H

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/WriteBytestream.h>

namespace JXMPP {
    class JXMPP_API ByteArrayWriteBytestream : public WriteBytestream {
        public:
            ByteArrayWriteBytestream() {
            }

            virtual bool write(const std::vector<unsigned char>& bytes) {
                data.insert(data.end(), bytes.begin(), bytes.end());
                onWrite(bytes);
                return true;
            }

            const std::vector<unsigned char>& getData() const {
                return data;
            }

        private:
            std::vector<unsigned char> data;
    };
}

#endif // JXMPP_BYTEARRAYWRITEBYTESTREAM_H
