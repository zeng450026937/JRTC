#ifndef JXMPP_MESSAGE_H
#define JXMPP_MESSAGE_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Body.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/Replace.h>
#include <JXMPP/Elements/Stanza.h>
#include <JXMPP/Elements/Subject.h>

namespace JXMPP {
    class JXMPP_API Message : public Stanza {
      public:
            typedef std::shared_ptr<Message> ref;

            enum Type { Normal, Chat, Error, Groupchat, Headline };

            Message() : type_(Chat) { }

            std::string getSubject() const {
                std::shared_ptr<Subject> subject(getPayload<Subject>());
                if (subject) {
                    return subject->getText();
                }
                return "";
            }

            void setSubject(const std::string& subject) {
                updatePayload(std::make_shared<Subject>(subject));
            }

            bool hasSubject() {
                return getPayload<Subject>() != nullptr;
            }

            boost::optional<std::string> getBody() const {
                std::shared_ptr<Body> body(getPayload<Body>());
                boost::optional<std::string> bodyData;
                if (body) {
                    bodyData = body->getText();
                }
                return bodyData;
            }

            void setBody(const std::string& body) {
                setBody(boost::optional<std::string>(body));
            }

            void setBody(const boost::optional<std::string>& body) {
                if (body) {
                    updatePayload(std::make_shared<Body>(body.get()));
                }
                else {
                    removePayloadOfSameType(std::make_shared<Body>());
                }
            }

            bool isError() {
                std::shared_ptr<JXMPP::ErrorPayload> error(getPayload<JXMPP::ErrorPayload>());
                return getType() == Message::Error || error;
            }

            Type getType() const { return type_; }
            void setType(Type type) { type_ = type; }

        private:
            Type type_;
    };
}

#endif // JXMPP_MESSAGE_H
