#ifndef JXMPP_AUTHSUCCESS_H
#define JXMPP_AUTHSUCCESS_H

#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API AuthSuccess : public ToplevelElement {
        public:
            AuthSuccess() {}

            const boost::optional<std::vector<unsigned char> >& getValue() const {
                return value;
            }

            void setValue(const std::vector<unsigned char>& value) {
                this->value = boost::optional<std::vector<unsigned char> >(value);
            }

        private:
            boost::optional<std::vector<unsigned char> > value;
    };
}

#endif // JXMPP_AUTHSUCCESS_H
