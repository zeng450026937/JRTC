#ifndef JXMPP_COCOAEVENT_H
#define JXMPP_COCOAEVENT_H

#include <Foundation/Foundation.h>

// The following line is a workaround for a bug in Boost 1.60 when building as C++11.
// See ticket #11897 and #11863 in Boost's bug tracker.
#undef check

namespace JXMPP {
    class CocoaEventLoop;
}

// Using deprecated declaration of instance vars in interface, because this
// is required for older runtimes (e.g. 32-bit Mac OS X)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-interface-ivars"

@interface CocoaEvent : NSObject {
    JXMPP::CocoaEventLoop* eventLoop;
}

#pragma clang diagnostic pop

// Takes ownership of event
- (id) init:(JXMPP::CocoaEventLoop*) el;
- (void) process;
- (void) dealloc;

@end

#endif // JXMPP_COCOAEVENT_H
