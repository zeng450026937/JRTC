#ifndef JXMPP_ZLIBCODECOMPRESSOR_PRIVATE_H
#define JXMPP_ZLIBCODECOMPRESSOR_PRIVATE_H

#include <zlib.h>

#include <JXMPP/Compress/ZLibCodecompressor.h>

namespace JXMPP {
    struct ZLibCodecompressor::Private {
        z_stream stream;
    };
}

#endif // JXMPP_ZLIBCODECOMPRESSOR_PRIVATE_H
