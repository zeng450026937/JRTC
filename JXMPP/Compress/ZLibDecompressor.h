#ifndef JXMPP_ZLIBDECOMPRESSOR_H
#define JXMPP_ZLIBDECOMPRESSOR_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Compress/ZLibCodecompressor.h>

namespace JXMPP {
    class JXMPP_API ZLibDecompressor : public ZLibCodecompressor {
        public:
            ZLibDecompressor();
            virtual ~ZLibDecompressor();

            virtual int processZStream();
    };
}

#endif // JXMPP_ZLIBDECOMPRESSOR_H
