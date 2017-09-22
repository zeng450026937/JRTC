#ifndef JXMPP_DATETIME_H
#define JXMPP_DATETIME_H

#include <boost/date_time/posix_time/ptime.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    /**
     * Converts a date formatted according to XEP-0082 into a ptime
     * object (in UTC).
     */
    JXMPP_API boost::posix_time::ptime stringToDateTime(const std::string& string);

    /**
     * Converts a UTC ptime object to a XEP-0082 formatted string.
     */
    JXMPP_API std::string dateTimeToString(const boost::posix_time::ptime& time);

    /**
     * Converts a UTC ptime object to a localized human readable string.
     */
    JXMPP_API std::string dateTimeToLocalString(const boost::posix_time::ptime& time);
}

#endif // JXMPP_DATETIME_H
