#ifndef JXMPP_XMLBEAUTIFIER_H
#define JXMPP_XMLBEAUTIFIER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>
#include <sstream>
#include <stack>
#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/XMLParser.h>
#include <JXMPP/Parser/XMLParserClient.h>
#include <JXMPP/Parser/XMLParserFactory.h>

namespace JXMPP {

class JXMPP_API XMLBeautifier : public XMLParserClient {
public:

    XMLBeautifier(bool indention, bool coloring);

    std::string beautify(const std::string&);
    bool wasReset() const;
    int getLevel() const;

private:
    void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes);
    void handleEndElement(const std::string& element, const std::string& ns);
    void handleCharacterData(const std::string& data);

private:
    void indent();
    void reset();

private:
    std::string styleTag(const std::string& text) const;
    std::string styleNamespace(const std::string& text) const;
    std::string styleAttribute(const std::string& text) const;
    std::string styleValue(const std::string& text) const;

private:
    const bool doIndention_;
    const bool doColoring_;

    std::unique_ptr<XMLParserFactory> factory_;
    std::unique_ptr<XMLParser> parser_;

    bool wasReset_ = true;
    int intLevel_ = 0;
    bool lastWasStepDown_ = false;
    std::stringstream buffer_;
    std::stack<std::string> parentNSs_;
};
}

#endif // JXMPP_XMLBEAUTIFIER_H
