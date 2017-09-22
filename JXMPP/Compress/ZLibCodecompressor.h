#ifndef JXMPP_ZLIBCODECOMPRESSOR_H
#define JXMPP_ZLIBCODECOMPRESSOR_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API ZLibCodecompressor {
        public:
            ZLibCodecompressor();
            virtual ~ZLibCodecompressor();

            SafeByteArray process(const SafeByteArray& data);
            virtual int processZStream() = 0;

        protected:
            struct Private;
            const std::unique_ptr<Private> p;
    };
}

#endif // JXMPP_ZLIBCODECOMPRESSOR_H
