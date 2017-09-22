#ifndef JXMPP_CONNECTIONFACTORY_H
#define JXMPP_CONNECTIONFACTORY_H

#include <memory>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class Connection;

    class JXMPP_API ConnectionFactory {
        public:
            virtual ~ConnectionFactory();

            virtual std::shared_ptr<Connection> createConnection() = 0;
    };
}

#endif // JXMPP_CONNECTIONFACTORY_H
