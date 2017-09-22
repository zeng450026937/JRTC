#ifndef JXMPP_IDLE_H
#define JXMPP_IDLE_H

/*
 * Copyright (c) 2013 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {

    class JXMPP_API Idle : public Payload {
    public:
        typedef std::shared_ptr<Idle> ref;

    public:
        Idle() {}
        Idle(boost::posix_time::ptime since) : since_(since) {
        }

        void setSince(boost::posix_time::ptime since) {
            since_ = since;
        }

        boost::posix_time::ptime getSince() const {
            return since_;
        }

    private:
        boost::posix_time::ptime since_;
    };

}

#endif // JXMPP_IDLE_H
