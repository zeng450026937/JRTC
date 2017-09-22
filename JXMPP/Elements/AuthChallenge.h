#ifndef JXMPP_AUTHCHALLENGE_H
#define JXMPP_AUTHCHALLENGE_H

#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API AuthChallenge : public ToplevelElement {
        public:
            AuthChallenge() {
            }

            AuthChallenge(const std::vector<unsigned char>& value) : value(value) {
            }

            const boost::optional< std::vector<unsigned char> >& getValue() const {
                return value;
            }

            void setValue(const std::vector<unsigned char>& value) {
                this->value = boost::optional<std::vector<unsigned char> >(value);
            }

        private:
            boost::optional< std::vector<unsigned char> > value;
    };
}

#endif // JXMPP_AUTHCHALLENGE_H
