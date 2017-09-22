#ifndef JXMPP_BYTEARRAYREADBYTESTREAM_H
#define JXMPP_BYTEARRAYREADBYTESTREAM_H

#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/FileTransfer/ReadBytestream.h>

namespace JXMPP {
    class JXMPP_API ByteArrayReadBytestream : public ReadBytestream {
        public:
            ByteArrayReadBytestream(const std::vector<unsigned char>& data) : data(data), position(0), dataComplete(true) {
            }

            virtual std::shared_ptr<ByteArray> read(size_t size);

            virtual bool isFinished() const {
                return position >= data.size() && dataComplete;
            }

            virtual void setDataComplete(bool b) {
                dataComplete = b;
            }

            void addData(const std::vector<unsigned char>& moreData);

        private:
            std::vector<unsigned char> data;
            size_t position;
            bool dataComplete;
    };
}

#endif // JXMPP_BYTEARRAYREADBYTESTREAM_H
