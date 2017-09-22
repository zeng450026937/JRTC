#ifndef JXMPP_BYTESTREAMS_H
#define JXMPP_BYTESTREAMS_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API Bytestreams : public Payload {
        public:
            typedef std::shared_ptr<Bytestreams> ref;

            struct StreamHost {
                StreamHost(const std::string& host = "", const JID& jid = JID(), int port = -1) : host(host), jid(jid), port(port) {}

                std::string host;
                JID jid;
                int port;
            };

            Bytestreams() {}

            const std::string& getStreamID() const {
                return id;
            }

            void setStreamID(const std::string& id) {
                this->id = id;
            }

            const boost::optional<JID>& getUsedStreamHost() const {
                return usedStreamHost;
            }

            void setUsedStreamHost(const JID& host) {
                usedStreamHost = host;
            }

            const std::vector<StreamHost>& getStreamHosts() const {
                return streamHosts;
            }

            void addStreamHost(const StreamHost& streamHost) {
                streamHosts.push_back(streamHost);
            }

        private:
            std::string id;
            boost::optional<JID> usedStreamHost;
            std::vector<StreamHost> streamHosts;
    };
}

#endif // JXMPP_BYTESTREAMS_H
