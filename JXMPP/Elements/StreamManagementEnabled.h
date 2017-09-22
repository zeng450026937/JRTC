#ifndef JXMPP_STREAMMANAGEMENTENABLED_H
#define JXMPP_STREAMMANAGEMENTENABLED_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API StreamManagementEnabled : public ToplevelElement {
        public:
            StreamManagementEnabled();
            ~StreamManagementEnabled();

            void setResumeSupported() {
                resumeSupported = true;
            }

            bool getResumeSupported() const {
                return resumeSupported;
            }

            void setResumeID(const std::string& id) {
                resumeID = id;
            }

            const std::string& getResumeID() const {
                return resumeID;
            }

        private:
            bool resumeSupported;
            std::string resumeID;
    };
}

#endif // JXMPP_STREAMMANAGEMENTENABLED_H
