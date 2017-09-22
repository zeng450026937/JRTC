#ifndef JXMPP_WRITEBYTESTREAM_H
#define JXMPP_WRITEBYTESTREAM_H

#include <memory>
#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API WriteBytestream {
        public:
            typedef std::shared_ptr<WriteBytestream> ref;

            virtual ~WriteBytestream();

            /**
             * Write data from vector argument to bytestream.
             *
             * On success true is returned and \ref onWrite is called. On failure false is returned.
             */
            virtual bool write(const std::vector<unsigned char>&) = 0;
            virtual void close() {}

            boost::signals2::signal<void (const std::vector<unsigned char>&)> onWrite;
    };
}

#endif // JXMPP_WRITEBYTESTREAM_H
