#include <JXMPP/EventLoop/Cocoa/CocoaEvent.h>

#include <JXMPP/EventLoop/Cocoa/CocoaEventLoop.h>

@implementation CocoaEvent

- (id) init:(JXMPP::CocoaEventLoop*) el {
    self = [super init];
    if (self != nil) {
        eventLoop = el;
    }
    return self;
}

- (void) process {
    eventLoop->handleNextCocoaEvent();
}

- (void) dealloc {
    [super dealloc];
}

@end
