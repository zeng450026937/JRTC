#ifndef JXMPP_STREAMRESUME_H
#define JXMPP_STREAMRESUME_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API StreamResume : public ToplevelElement {
        public:
            StreamResume();
            ~StreamResume();

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

#endif // JXMPP_STREAMRESUME_H
