#include <JXMPP/IDN/PlatformIDNConverter.h>
#if defined(HAVE_LIBIDN)
#include <JXMPP/IDN/LibIDNConverter.h>
#elif defined(HAVE_ICU)
#include <JXMPP/IDN/ICUConverter.h>
#endif

namespace JXMPP {

IDNConverter* PlatformIDNConverter::create() {
#if defined(HAVE_LIBIDN)
    return new LibIDNConverter();
#elif defined(HAVE_ICU)
    return new ICUConverter();
#else
#if defined(NEED_IDN)
#error "No IDN implementation"
#endif
    return nullptr;
#endif
}

}
