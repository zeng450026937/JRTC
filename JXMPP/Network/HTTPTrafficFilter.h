#ifndef JXMPP_HTTPTRAFFICFILTER_H
#define JXMPP_HTTPTRAFFICFILTER_H

#include <string>
#include <utility>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {

class JXMPP_API HTTPTrafficFilter {
    public:
        virtual ~HTTPTrafficFilter();
        /**
         * @brief This method is called by the HTTPConnectPRoxiedConnection on every incoming HTTP response.
         *        It can be used to insert additional HTTP requests into the HTTP CONNECT proxy initalization process.
         * @return A vector of HTTP header fields to use in a new request. If an empty vector is returned,
         *         no new request will be send and the normal proxy logic continues.
         */
        virtual std::vector<std::pair<std::string, std::string> > filterHTTPResponseHeader(const std::string& statusLine, const std::vector<std::pair<std::string, std::string> >& /* responseHeader */) = 0;
};

}

#endif // JXMPP_HTTPTRAFFICFILTER_H
