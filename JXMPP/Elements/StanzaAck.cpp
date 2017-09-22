#include <JXMPP/Elements/StanzaAck.h>

#include <boost/numeric/conversion/cast.hpp>

using namespace JXMPP;

StanzaAck::~StanzaAck() {
}

void StanzaAck::setHandledStanzasCount(int i) {
    handledStanzasCount = boost::numeric_cast<unsigned int>(i);
    valid = true;
}
