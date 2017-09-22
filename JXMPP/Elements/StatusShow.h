#ifndef JXMPP_STATUSSHOW_H
#define JXMPP_STATUSSHOW_H

#include <cassert>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API StatusShow : public Payload {
        public:
            enum Type { Online, Away, FFC, XA, DND, None };

            StatusShow(const Type& type = Online);

            void setType(const Type& type) {
                type_ = type;
            }

            const Type& getType() const {
                return type_;
            }

            /**
             * Can be used for rough ordering of Types.
             * Greater magnitude = more available.
             */
            static int typeToAvailabilityOrdering(Type type) {
                switch (type) {
                    case Online: return 4;
                    case FFC: return 5;
                    case Away: return 2;
                    case XA: return 1;
                    case DND: return 3;
                    case None: return 0;
                }
                assert(false);
                return 0;
            }

        private:
            Type type_;
    };
}

#endif // JXMPP_STATUSSHOW_H
