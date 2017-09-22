#ifndef JXMPP_MAMFIN_H
#define JXMPP_MAMFIN_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/ResultSet.h>

namespace JXMPP {
    class JXMPP_API MAMFin : public Payload {
        public:
            MAMFin() : isComplete_(false), isStable_(true) {}
            virtual ~MAMFin();

            void setComplete(const bool isComplete) {
                isComplete_ = isComplete;
            }

            bool isComplete() const {
                return isComplete_;
            }

            void setStable(const bool isStable) {
                isStable_ = isStable;
            }

            bool isStable() const {
                return isStable_;
            }

            void setResultSet(std::shared_ptr<ResultSet> resultSet) {
                resultSet_ = resultSet;
            }

            std::shared_ptr<ResultSet> getResultSet() const {
                return resultSet_;
            }

            void setQueryID(const std::string& queryID) {
                queryID_ = queryID;
            }

            const boost::optional<std::string>& getQueryID() const {
                return queryID_;
            }


        private:
            bool isComplete_;
            bool isStable_;
            std::shared_ptr<ResultSet> resultSet_;
            boost::optional<std::string> queryID_;
    };
}

#endif // JXMPP_MAMFIN_H
