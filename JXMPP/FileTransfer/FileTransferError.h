#ifndef JXMPP_FILETRANSFERERROR_H
#define JXMPP_FILETRANSFERERROR_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API FileTransferError {
        public:
            enum Type {
                UnknownError,
                PeerError,
                ReadError,
                WriteError,
                ClosedError
            };

            FileTransferError(Type type = UnknownError) : type(type) {}

            Type getType() const {
                return type;
            }

        private:
            Type type;
    };
}

#endif // JXMPP_FILETRANSFERERROR_H
