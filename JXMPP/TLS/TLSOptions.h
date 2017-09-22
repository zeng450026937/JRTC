#ifndef JXMPP_TLSOPTIONS_H
#define JXMPP_TLSOPTIONS_H

namespace JXMPP {

    struct TLSOptions {
        TLSOptions() : schannelTLS1_0Workaround(false) {

        }

        /**
         * A bug in the Windows SChannel TLS stack, combined with
         * overly-restrictive server stacks means it's sometimes necessary to
         * not use TLS>1.0. This option has no effect unless compiled on
         * Windows against SChannel (OpenSSL users are unaffected).
         */
        bool schannelTLS1_0Workaround;

    };
}

#endif // JXMPP_TLSOPTIONS_H
