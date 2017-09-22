#include <JXMPP/Base/SafeByteArray.h>

#include <JXMPP/Base/Platform.h>
#ifdef JXMPP_PLATFORM_WINDOWS
#include <windows.h>
#endif

namespace JXMPP {

JXMPP_API void secureZeroMemory(char* memory, size_t numberOfBytes) {
#ifdef JXMPP_PLATFORM_WINDOWS
    SecureZeroMemory(memory, numberOfBytes);
#else
    volatile char* p = memory;
    for (size_t i = 0; i < numberOfBytes; ++i) {
        *(p++) = 0;
    }
#endif
}

}
