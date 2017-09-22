#ifndef JXMPP_PATHS_H
#define JXMPP_PATHS_H

#include <boost/filesystem/path.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API Paths {
        public:
            static boost::filesystem::path getExecutablePath();
    };
}

#endif // JXMPP_PATHS_H
