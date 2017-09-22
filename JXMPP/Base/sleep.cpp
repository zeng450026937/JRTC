#include <JXMPP/Base/sleep.h>

#include <chrono>
#include <thread>

namespace JXMPP {

void sleep(unsigned int msecs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(msecs));
}

}
