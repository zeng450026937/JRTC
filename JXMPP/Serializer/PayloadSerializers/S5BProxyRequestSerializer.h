#ifndef JXMPP_S5BPROXYREQUESTSERIALIZER_H
#define JXMPP_S5BPROXYREQUESTSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/S5BProxyRequest.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API S5BProxyRequestSerializer : public GenericPayloadSerializer<S5BProxyRequest> {
        public:
            virtual std::string serializePayload(std::shared_ptr<S5BProxyRequest> s5bProxyRequest) const {
                XMLElement queryElement("query", "http://jabber.org/protocol/bytestreams");
                if (s5bProxyRequest && s5bProxyRequest->getStreamHost()) {
                    std::shared_ptr<XMLElement> streamHost = std::make_shared<XMLElement>("streamhost");
                    streamHost->setAttribute("host", s5bProxyRequest->getStreamHost().get().host);
                    streamHost->setAttribute("port", boost::lexical_cast<std::string>(s5bProxyRequest->getStreamHost().get().port));
                    streamHost->setAttribute("jid", s5bProxyRequest->getStreamHost().get().jid.toString());
                    queryElement.addNode(streamHost);
                } else if (s5bProxyRequest && s5bProxyRequest->getActivate()) {
                    queryElement.setAttribute("sid", s5bProxyRequest->getSID());
                    std::shared_ptr<XMLElement> activate = std::make_shared<XMLElement>("activate", "", s5bProxyRequest->getActivate().get().toString());
                    queryElement.addNode(activate);
                }
                return queryElement.serialize();
            }
    };
}

#endif // JXMPP_S5BPROXYREQUESTSERIALIZER_H
