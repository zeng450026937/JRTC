#include <JXMPP/Jingle/JingleSession.h>

#include <algorithm>
#include <cassert>
#include <memory>

#include <boost/function.hpp>

using namespace JXMPP;

JingleSession::JingleSession(const JID& initiator, const std::string& id) : initiator(initiator), id(id) {
    // initiator must always be a full JID; session lookup based on it wouldn't work otherwise
    // this is checked on an upper level so that the assert never fails
    assert(!initiator.isBare());
}

JingleSession::~JingleSession() {
}
