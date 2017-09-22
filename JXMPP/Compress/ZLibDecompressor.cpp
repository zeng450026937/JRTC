#include <JXMPP/Compress/ZLibDecompressor.h>

#include <zlib.h>
#include <cassert>

#include <JXMPP/Compress/ZLibCodecompressor_Private.h>

#pragma GCC diagnostic ignored "-Wold-style-cast"

namespace JXMPP {

ZLibDecompressor::ZLibDecompressor() {
    int result = inflateInit(&p->stream);
    assert(result == Z_OK);
    (void) result;
}

ZLibDecompressor::~ZLibDecompressor() {
    inflateEnd(&p->stream);
}

int ZLibDecompressor::processZStream() {
    return inflate(&p->stream, Z_SYNC_FLUSH);
}

}
