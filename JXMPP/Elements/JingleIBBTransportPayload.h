#ifndef JXMPP_JINGLEIBBTRANSPORTPAYLOAD_H
#define JXMPP_JINGLEIBBTRANSPORTPAYLOAD_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleTransportPayload.h>

namespace JXMPP {
    class JXMPP_API JingleIBBTransportPayload : public JingleTransportPayload {
        public:
            typedef std::shared_ptr<JingleIBBTransportPayload> ref;

            enum StanzaType {
                IQStanza,
                MessageStanza
            };

            JingleIBBTransportPayload() : stanzaType(IQStanza) {
            }

            void setStanzaType(StanzaType stanzaType) {
                this->stanzaType = stanzaType;
            }

            StanzaType getStanzaType() const {
                return stanzaType;
            }

            boost::optional<unsigned int> getBlockSize() const {
                return blockSize;
            }

            void setBlockSize(unsigned int blockSize) {
                this->blockSize = blockSize;
            }

        private:
            boost::optional<unsigned int> blockSize;
            StanzaType stanzaType;
    };
}

#endif // JXMPP_JINGLEIBBTRANSPORTPAYLOAD_H
