#ifndef JXMPP_DUMMYIQCHANNEL_H
#define JXMPP_DUMMYIQCHANNEL_H

#include <vector>

#include <JXMPP/Queries/IQChannel.h>

namespace JXMPP {
    class DummyIQChannel : public IQChannel {
        public:
            DummyIQChannel() {}

            virtual void sendIQ(std::shared_ptr<IQ> iq) {
                iqs_.push_back(iq);
            }

            virtual std::string getNewIQID() {
                return "test-id";
            }

            virtual bool isAvailable() const {
                return true;
            }

            std::vector<std::shared_ptr<IQ> > iqs_;
    };
}

#endif // JXMPP_DUMMYIQCHANNEL_H
