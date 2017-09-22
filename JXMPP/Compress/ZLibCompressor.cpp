#include <JXMPP/Compress/ZLibCompressor.h>

#include <cassert>
#include <zlib.h>

#include <JXMPP/Compress/ZLibCodecompressor_Private.h>

#pragma GCC diagnostic ignored "-Wold-style-cast"

namespace JXMPP {

ZLibCompressor::ZLibCompressor() {
    int result = deflateInit(&p->stream, COMPRESSION_LEVEL);
    assert(result == Z_OK);
    (void) result;
}

ZLibCompressor::~ZLibCompressor() {
    deflateEnd(&p->stream);
}

int ZLibCompressor::processZStream() {
    return deflate(&p->stream, Z_SYNC_FLUSH);
}

}
