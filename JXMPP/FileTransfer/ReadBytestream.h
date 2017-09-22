#ifndef JXMPP_READBYTESTREAM_H
#define JXMPP_READBYTESTREAM_H

#include <memory>
#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API ReadBytestream {
        public:
            virtual ~ReadBytestream();

            /**
             * Return an empty vector if no more data is available.
             * Use onDataAvailable signal for signaling there is data available again.
             */
            virtual std::shared_ptr< std::vector<unsigned char> > read(size_t size) = 0;

            virtual bool isFinished() const = 0;

        public:
            boost::signals2::signal<void ()> onDataAvailable;
            boost::signals2::signal<void (const std::vector<unsigned char>&)> onRead;
    };
}

#endif // JXMPP_READBYTESTREAM_H
