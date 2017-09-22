#ifndef JXMPP_JINGLEFILETRANSFERDESCRIPTION_H
#define JXMPP_JINGLEFILETRANSFERDESCRIPTION_H

#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleDescription.h>
#include <JXMPP/Elements/JingleFileTransferFileInfo.h>

namespace JXMPP {
    class JXMPP_API JingleFileTransferDescription : public JingleDescription {
        public:
            typedef std::shared_ptr<JingleFileTransferDescription> ref;

            void setFileInfo(const JingleFileTransferFileInfo& fileInfo) {
                fileInfo_ = fileInfo;
            }

            const JingleFileTransferFileInfo& getFileInfo() {
                return fileInfo_;
            }

        private:
            JingleFileTransferFileInfo fileInfo_;
    };
}

#endif // JXMPP_JINGLEFILETRANSFERDESCRIPTION_H
