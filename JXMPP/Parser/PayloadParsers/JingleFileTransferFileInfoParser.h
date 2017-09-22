#ifndef JXMPP_JINGLEFILETRANSFERFILEINFOPARSER_H
#define JXMPP_JINGLEFILETRANSFERFILEINFOPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleFileTransferFileInfo.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {

class JXMPP_API JingleFileTransferFileInfoParser : public GenericPayloadParser<JingleFileTransferFileInfo> {
    public:
        JingleFileTransferFileInfoParser();

        virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
        virtual void handleEndElement(const std::string& element, const std::string&);
        virtual void handleCharacterData(const std::string& data);

    private:
        int level;
        std::string charData;
        std::string hashAlg;
        boost::optional<boost::uintmax_t> rangeOffset;
};

}

#endif // JXMPP_JINGLEFILETRANSFERFILEINFOPARSER_H
