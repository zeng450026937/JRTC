#ifndef JXMPP_JINGLECONTENTPAYLOAD_H
#define JXMPP_JINGLECONTENTPAYLOAD_H

#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleDescription.h>
#include <JXMPP/Elements/JingleTransportPayload.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API JingleContentPayload : public Payload {
        public:
            typedef std::shared_ptr<JingleContentPayload> ref;

            enum Creator {
                UnknownCreator,
                InitiatorCreator,
                ResponderCreator
            };

            JingleContentPayload() : creator(UnknownCreator) {
            }

            /*enum Senders {
                NoSenders,
                InitiatorSender,
                ResponderSender,
                BothSenders,
            };*/

            Creator getCreator() const {
                return creator;
            }

            void setCreator(Creator creator) {
                this->creator = creator;
            }

            const std::string& getName() const {
                return name;
            }

            void setName(const std::string& name) {
                this->name = name;
            }

            const std::vector<JingleDescription::ref>& getDescriptions() const {
                return descriptions;
            }

            void addDescription(JingleDescription::ref description) {
                descriptions.push_back(description);
            }

            const std::vector<std::shared_ptr<JingleTransportPayload> >& getTransports() const {
                return transports;
            }

            void addTransport(std::shared_ptr<JingleTransportPayload>  transport) {
                transports.push_back(transport);
            }

            template<typename T>
            std::shared_ptr<T> getDescription() const {
                for (const auto& description : descriptions) {
                    std::shared_ptr<T> result(std::dynamic_pointer_cast<T>(description));
                    if (result) {
                        return result;
                    }
                }
                return std::shared_ptr<T>();
            }

            template<typename T>
            std::shared_ptr<T> getTransport() const {
                for (const auto& transport : transports) {
                    std::shared_ptr<T> result(std::dynamic_pointer_cast<T>(transport));
                    if (result) {
                        return result;
                    }
                }
                return std::shared_ptr<T>();
            }

        private:
            Creator creator;
            std::string name;
            //Senders senders;
            std::vector<JingleDescription::ref> descriptions;
            std::vector<std::shared_ptr<JingleTransportPayload> > transports;
    };
}

#endif // JXMPP_JINGLECONTENTPAYLOAD_H
