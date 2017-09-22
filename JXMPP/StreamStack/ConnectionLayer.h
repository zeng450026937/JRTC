#ifndef JXMPP_CONNECTIONLAYER_H
#define JXMPP_CONNECTIONLAYER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/StreamStack/LowLayer.h>

namespace JXMPP {
    class JXMPP_API ConnectionLayer : public LowLayer {
        public:
            ConnectionLayer(std::shared_ptr<Connection> connection);
            virtual ~ConnectionLayer();

            void writeData(const SafeByteArray& data) {
                connection->write(data);
            }

        private:
            void handleDataRead(std::shared_ptr<SafeByteArray>);

        private:
            std::shared_ptr<Connection> connection;
    };
}

#endif // JXMPP_CONNECTIONLAYER_H
