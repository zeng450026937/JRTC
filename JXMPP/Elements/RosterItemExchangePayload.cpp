/*
 * Copyright (c) 2011 Jan Kaluza
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Elements/RosterItemExchangePayload.h>

namespace JXMPP {

RosterItemExchangePayload::Item::Item(Action action) : action(action) {
}

RosterItemExchangePayload::RosterItemExchangePayload() {
}

}
