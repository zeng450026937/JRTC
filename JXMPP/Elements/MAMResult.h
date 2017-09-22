#ifndef JXMPP_MAMRESULT_H
#define JXMPP_MAMRESULT_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ContainerPayload.h>
#include <JXMPP/Elements/Forwarded.h>

namespace JXMPP {
    class JXMPP_API MAMResult : public ContainerPayload<Forwarded> {
        public:
            virtual ~MAMResult();

            void setID(const std::string& id) { id_ = id; }
            const std::string& getID() const { return id_; }

            void setQueryID(const boost::optional<std::string>& queryID) { queryID_ = queryID; }
            const boost::optional<std::string>& getQueryID() const { return queryID_; }

        private:
            std::string id_;
            boost::optional<std::string> queryID_;
    };
}

#endif // JXMPP_MAMRESULT_H
