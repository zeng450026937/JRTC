#ifndef JXMPP_ERRORPAYLOAD_H
#define JXMPP_ERRORPAYLOAD_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API ErrorPayload : public Payload {
        public:
            typedef std::shared_ptr<ErrorPayload> ref;

            enum Type { Cancel, Continue, Modify, Auth, Wait };

            enum Condition {
                BadRequest,
                Conflict,
                FeatureNotImplemented,
                Forbidden,
                Gone,
                InternalServerError,
                ItemNotFound,
                JIDMalformed,
                NotAcceptable,
                NotAllowed,
                NotAuthorized,
                PaymentRequired,
                RecipientUnavailable,
                Redirect,
                RegistrationRequired,
                RemoteServerNotFound,
                RemoteServerTimeout,
                ResourceConstraint,
                ServiceUnavailable,
                SubscriptionRequired,
                UndefinedCondition,
                UnexpectedRequest
            };

            ErrorPayload(Condition condition = UndefinedCondition, Type type = Cancel, const std::string& text = std::string()) : type_(type), condition_(condition), text_(text) { }

            Type getType() const {
                return type_;
            }

            void setType(Type type) {
                type_ = type;
            }

            Condition getCondition() const {
                return condition_;
            }

            void setCondition(Condition condition) {
                condition_ = condition;
            }

            void setText(const std::string& text) {
                text_ = text;
            }

            const std::string& getText() const {
                return text_;
            }

            void setPayload(std::shared_ptr<Payload> payload) {
                payload_ = payload;
            }

            std::shared_ptr<Payload> getPayload() const {
                return payload_;
            }

        private:
            Type type_;
            Condition condition_;
            std::string text_;
            std::shared_ptr<Payload> payload_;
    };
}

#endif // JXMPP_ERRORPAYLOAD_H