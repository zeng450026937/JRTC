#include <JXMPP/Base/Path.h>

#include <JXMPP/Base/Platform.h>
#include <JXMPP/Base/String.h>

using namespace JXMPP;

boost::filesystem::path JXMPP::stringToPath(const std::string& path) {
#ifdef JXMPP_PLATFORM_WINDOWS
    return boost::filesystem::path(convertStringToWString(path));
#else
    return boost::filesystem::path(path);
#endif
}

std::string JXMPP::pathToString(const boost::filesystem::path& path) {
#ifdef JXMPP_PLATFORM_WINDOWS
    return convertWStringToString(path.native());
#else
    return path.native();
#endif
}
