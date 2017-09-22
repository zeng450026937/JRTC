#ifndef JXMPP_BYTESTREAMEXCEPTION_H
#define JXMPP_BYTESTREAMEXCEPTION_H

#include <stdexcept>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API BytestreamException : public std::exception {
        public:
            BytestreamException() {
            }
    };
}

#endif // JXMPP_BYTESTREAMEXCEPTION_H
