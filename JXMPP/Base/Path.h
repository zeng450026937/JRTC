#ifndef JXMPP_PATH_H
#define JXMPP_PATH_H

#include <string>

#include <boost/filesystem/path.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    /**
     * Creates a path for the given UTF-8 encoded string.
     * This works independently of global locale settings.
     */
    JXMPP_API boost::filesystem::path stringToPath(const std::string&);

    /**
     * Returns the UTF-8 representation of the given path
     * This works independently of global locale settings.
     */
    JXMPP_API std::string pathToString(const boost::filesystem::path&);
}

#endif // JXMPP_PATH_H
