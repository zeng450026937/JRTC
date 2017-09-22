#include <JXMPP/Elements/FormField.h>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace JXMPP;

FormField::~FormField() {
}

std::string FormField::getTextMultiValue() const {
    assert(type == TextMultiType || type == UnknownType);
    return boost::algorithm::join(values, "\n");
}

void FormField::setTextMultiValue(const std::string& value) {
    assert(type == TextMultiType || type == UnknownType);
    values.clear();
    boost::split(values, value, boost::is_any_of("\n"));
}

void FormField::setBoolValue(bool b) {
    values.clear();
    values.push_back(b ? "1" : "0");
}
