#ifndef JXMPP_FORMAT_H
#define JXMPP_FORMAT_H

#include <iostream>

#include <boost/format.hpp>

namespace JXMPP {
    inline boost::format format(const std::string& s) {
        using namespace boost::io;
        try {
            boost::format fmter(s);
            fmter.exceptions(no_error_bits);
            return fmter;
        }
        catch (...) {
            std::cerr << "Error: Invalid translation: " << s << std::endl;
            throw;
        }
    }
}

#endif // JXMPP_FORMAT_H
