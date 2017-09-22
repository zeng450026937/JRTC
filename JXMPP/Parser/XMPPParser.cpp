#include <JXMPP/Parser/XMPPParser.h>

#include <cassert>
#include <string>

#include <JXMPP/Elements/ProtocolHeader.h>
#include <JXMPP/Parser/AuthChallengeParser.h>
#include <JXMPP/Parser/AuthFailureParser.h>
#include <JXMPP/Parser/AuthRequestParser.h>
#include <JXMPP/Parser/AuthResponseParser.h>
#include <JXMPP/Parser/AuthSuccessParser.h>
#include <JXMPP/Parser/ComponentHandshakeParser.h>
#include <JXMPP/Parser/CompressFailureParser.h>
#include <JXMPP/Parser/CompressParser.h>
#include <JXMPP/Parser/CompressedParser.h>
#include <JXMPP/Parser/ElementParser.h>
#include <JXMPP/Parser/EnableStreamManagementParser.h>
#include <JXMPP/Parser/IQParser.h>
#include <JXMPP/Parser/MessageParser.h>
#include <JXMPP/Parser/PresenceParser.h>
#include <JXMPP/Parser/StanzaAckParser.h>
#include <JXMPP/Parser/StanzaAckRequestParser.h>
#include <JXMPP/Parser/StartTLSFailureParser.h>
#include <JXMPP/Parser/StartTLSParser.h>
#include <JXMPP/Parser/StreamErrorParser.h>
#include <JXMPP/Parser/StreamFeaturesParser.h>
#include <JXMPP/Parser/StreamManagementEnabledParser.h>
#include <JXMPP/Parser/StreamManagementFailedParser.h>
#include <JXMPP/Parser/StreamResumeParser.h>
#include <JXMPP/Parser/StreamResumedParser.h>
#include <JXMPP/Parser/TLSProceedParser.h>
#include <JXMPP/Parser/UnknownElementParser.h>
#include <JXMPP/Parser/XMLParser.h>
#include <JXMPP/Parser/XMLParserFactory.h>
#include <JXMPP/Parser/XMPPParserClient.h>

// TODO: Whenever an error occurs in the handlers, stop the parser by returing
// a bool value, and stopping the XML parser

namespace JXMPP {

XMPPParser::XMPPParser(
        XMPPParserClient* client,
        PayloadParserFactoryCollection* payloadParserFactories,
        XMLParserFactory* xmlParserFactory) :
                xmlParser_(nullptr),
                client_(client),
                payloadParserFactories_(payloadParserFactories),
                level_(0),
                currentElementParser_(nullptr),
                parseErrorOccurred_(false) {
    xmlParser_ = xmlParserFactory->createXMLParser(this);
}

XMPPParser::~XMPPParser() {
    delete currentElementParser_;
}

bool XMPPParser::parse(const std::string& data) {
    bool xmlParseResult = xmlParser_->parse(data);
    return xmlParseResult && !parseErrorOccurred_;
}

void XMPPParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (!parseErrorOccurred_) {
        if (level_ == TopLevel) {
            if (element == "stream" && ns == "http://etherx.jabber.org/streams") {
                ProtocolHeader header;
                header.setFrom(attributes.getAttribute("from"));
                header.setTo(attributes.getAttribute("to"));
                header.setID(attributes.getAttribute("id"));
                header.setVersion(attributes.getAttribute("version"));
                client_->handleStreamStart(header);
            }
            else {
                parseErrorOccurred_ = true;
            }
        }
        else {
            if (level_ == StreamLevel) {
                assert(!currentElementParser_);
                currentElementParser_ = createElementParser(element, ns);
            }
            currentElementParser_->handleStartElement(element, ns, attributes);
        }
    }
    ++level_;
}

void XMPPParser::handleEndElement(const std::string& element, const std::string& ns) {
    assert(level_ > TopLevel);
    --level_;
    if (!parseErrorOccurred_) {
        if (level_ == TopLevel) {
            assert(element == "stream");
            client_->handleStreamEnd();
        }
        else {
            assert(currentElementParser_);
            currentElementParser_->handleEndElement(element, ns);
            if (level_ == StreamLevel) {
                client_->handleElement(currentElementParser_->getElement());
                delete currentElementParser_;
                currentElementParser_ = nullptr;
            }
        }
    }
}

void XMPPParser::handleCharacterData(const std::string& data) {
    if (!parseErrorOccurred_) {
        if (currentElementParser_) {
            currentElementParser_->handleCharacterData(data);
        }
    //else {
    //    std::cerr << "XMPPParser: Ignoring stray character data: " << data << std::endl;
    //}
    }
}

ElementParser* XMPPParser::createElementParser(const std::string& element, const std::string& ns) {
    if (element == "presence") {
        return new PresenceParser(payloadParserFactories_);
    }
    else if (element == "iq") {
        return new IQParser(payloadParserFactories_);
    }
    else if (element == "message") {
        return new MessageParser(payloadParserFactories_);
    }
    else if (element == "features"  && ns == "http://etherx.jabber.org/streams") {
        return new StreamFeaturesParser();
    }
    else if (element == "error" && ns == "http://etherx.jabber.org/streams") {
        return new StreamErrorParser();
    }
    else if (element == "auth") {
        return new AuthRequestParser();
    }
    else if (element == "success") {
        return new AuthSuccessParser();
    }
    else if (element == "failure" && ns == "urn:ietf:params:xml:ns:xmpp-sasl") {
        return new AuthFailureParser();
    }
    else if (element == "challenge" && ns == "urn:ietf:params:xml:ns:xmpp-sasl") {
        return new AuthChallengeParser();
    }
    else if (element == "response" && ns == "urn:ietf:params:xml:ns:xmpp-sasl") {
        return new AuthResponseParser();
    }
    else if (element == "starttls") {
        return new StartTLSParser();
    }
    else if (element == "failure" && ns == "urn:ietf:params:xml:ns:xmpp-tls") {
        return new StartTLSFailureParser();
    }
    else if (element == "compress") {
        return new CompressParser();
    }
    else if (element == "compressed") {
        return new CompressedParser();
    }
    else if (element == "failure" && ns == "http://jabber.org/protocol/compress") {
        return new CompressFailureParser();
    }
    else if (element == "proceed") {
        return new TLSProceedParser();
    }
    else if (element == "enable" && ns == "urn:xmpp:sm:2") {
        return new EnableStreamManagementParser();
    }
    else if (element == "enabled" && ns == "urn:xmpp:sm:2") {
        return new StreamManagementEnabledParser();
    }
    else if (element == "failed" && ns == "urn:xmpp:sm:2") {
        return new StreamManagementFailedParser();
    }
    else if (element == "resume" && ns == "urn:xmpp:sm:2") {
        return new StreamResumeParser();
    }
    else if (element == "resumed" && ns == "urn:xmpp:sm:2") {
        return new StreamResumedParser();
    }
    else if (element == "a" && ns == "urn:xmpp:sm:2") {
        return new StanzaAckParser();
    }
    else if (element == "r" && ns == "urn:xmpp:sm:2") {
        return new StanzaAckRequestParser();
    }
    else if (element == "handshake") {
        return new ComponentHandshakeParser();
    }
    return new UnknownElementParser();
}

}
