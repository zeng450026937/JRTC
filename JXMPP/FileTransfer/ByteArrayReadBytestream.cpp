#include <JXMPP/FileTransfer/ByteArrayReadBytestream.h>

#include <memory>

#include <boost/numeric/conversion/cast.hpp>

#include <JXMPP/Base/Algorithm.h>

using namespace JXMPP;

std::shared_ptr<ByteArray> ByteArrayReadBytestream::read(size_t size) {
    size_t readSize = size;
    if (position + readSize > data.size()) {
        readSize = data.size() - position;
    }
    std::shared_ptr<ByteArray> result = std::make_shared<ByteArray>(
            data.begin() + boost::numeric_cast<long long>(position),
            data.begin() + boost::numeric_cast<long long>(position) + boost::numeric_cast<long long>(readSize));

    onRead(*result);
    position += readSize;
    return result;
}

void ByteArrayReadBytestream::addData(const std::vector<unsigned char>& moreData) {
    append(data, moreData);
    onDataAvailable();
}
