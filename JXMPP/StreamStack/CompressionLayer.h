#ifndef JXMPP_COMPRESSIONLAYER_H
#define JXMPP_COMPRESSIONLAYER_H

#include <boost/noncopyable.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Compress/ZLibCompressor.h>
#include <JXMPP/Compress/ZLibDecompressor.h>
#include <JXMPP/Compress/ZLibException.h>
#include <JXMPP/StreamStack/StreamLayer.h>

namespace JXMPP {
    class ZLibCompressor;
    class ZLibDecompressor;

    class JXMPP_API CompressionLayer : public StreamLayer, boost::noncopyable {
        public:
            CompressionLayer() {}

            virtual void writeData(const SafeByteArray& data) {
                try {
                    writeDataToChildLayer(compressor_.process(data));
                }
                catch (const ZLibException&) {
                    onError();
                }
            }

            virtual void handleDataRead(const SafeByteArray& data) {
                try {
                    writeDataToParentLayer(decompressor_.process(data));
                }
                catch (const ZLibException&) {
                    onError();
                }
            }

        public:
            boost::signals2::signal<void ()> onError;

        private:
            ZLibCompressor compressor_;
            ZLibDecompressor decompressor_;
    };
}

#endif // JXMPP_COMPRESSIONLAYER_H
