#ifndef JXMPP_FILESIZE_H
#define JXMPP_FILESIZE_H

#include <string>

#include <boost/cstdint.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {

JXMPP_API std::string formatSize(const boost::uintmax_t bytes);

}

#endif // JXMPP_FILESIZE_H
