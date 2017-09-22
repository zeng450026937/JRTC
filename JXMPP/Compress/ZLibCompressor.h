#ifndef JXMPP_ZLIBCOMPRESSOR_H
#define JXMPP_ZLIBCOMPRESSOR_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Compress/ZLibCodecompressor.h>

namespace JXMPP {
    class JXMPP_API ZLibCompressor : public ZLibCodecompressor {
        public:
            ZLibCompressor();
            virtual ~ZLibCompressor();

            virtual int processZStream();

        private:
            static const int COMPRESSION_LEVEL = 9;
    };
}

#endif // JXMPP_ZLIBCOMPRESSOR_H
