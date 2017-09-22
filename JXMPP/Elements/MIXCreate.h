#ifndef JXMPP_MIXCREATE_H
#define JXMPP_MIXCREATE_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <memory>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API MIXCreate : public Payload {
        public:
            using ref = std::shared_ptr<MIXCreate>;

        public:

            MIXCreate() {}

            std::shared_ptr<Form> getData() const {
                return data_;
            }

            void setData(std::shared_ptr<Form> value) {
                this->data_ = value ;
            }

            const boost::optional<std::string>& getChannel() const {
                return channel_;
            }

            void setChannel(const std::string& channel) {
                this->channel_ = channel;
            }

        private:
            boost::optional<std::string> channel_;
            std::shared_ptr<Form> data_;
    };
}

#endif // JXMPP_MIXCREATE_H
