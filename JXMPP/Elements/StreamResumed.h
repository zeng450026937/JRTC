#ifndef JXMPP_STREAMRESUMED_H
#define JXMPP_STREAMRESUMED_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API StreamResumed : public ToplevelElement {
        public:
            StreamResumed();
            ~StreamResumed();

            void setResumeID(const std::string& id) {
                resumeID = id;
            }

            const std::string& getResumeID() const {
                return resumeID;
            }

            const boost::optional<unsigned int> getHandledStanzasCount() const {
                return handledStanzasCount;
            }

            void setHandledStanzasCount(unsigned int i) {
                handledStanzasCount = i;
            }

        private:
            std::string resumeID;
            boost::optional<unsigned int> handledStanzasCount;
    };
}

#endif // JXMPP_STREAMRESUMED_H
