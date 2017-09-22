#ifndef JXMPP_JINGLEFILETRANSFERHASH_H
#define JXMPP_JINGLEFILETRANSFERHASH_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <map>
#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleDescription.h>
#include <JXMPP/Elements/JingleFileTransferFileInfo.h>

namespace JXMPP {

class JXMPP_API JingleFileTransferHash : public Payload {
public:
    typedef std::shared_ptr<JingleFileTransferHash> ref;

    void setFileInfo(const JingleFileTransferFileInfo& fileInfo) {
        fileInfo_ = fileInfo;
    }

    JingleFileTransferFileInfo& getFileInfo() {
        return fileInfo_;
    }

private:
    JingleFileTransferFileInfo fileInfo_;
};

}

#endif // JXMPP_JINGLEFILETRANSFERHASH_H
