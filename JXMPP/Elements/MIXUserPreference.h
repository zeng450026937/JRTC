#ifndef JXMPP_MIXUSERPREFERENCE_H
#define JXMPP_MIXUSERPREFERENCE_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API MIXUserPreference : public Payload {
        public:
            using ref = std::shared_ptr<MIXUserPreference>;

        public:

            MIXUserPreference() {}

            std::shared_ptr<Form> getData() const {
                return data_;
            }

            void setData(std::shared_ptr<Form> value) {
                this->data_ = value ;
            }


        private:
            std::shared_ptr<Form> data_;
    };
}

#endif // JXMPP_MIXUSERPREFERENCE_H
