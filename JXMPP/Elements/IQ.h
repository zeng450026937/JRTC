#ifndef JXMPP_IQ_H
#define JXMPP_IQ_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/Stanza.h>

namespace JXMPP {
    class JXMPP_API IQ : public Stanza {
        public:
            typedef std::shared_ptr<IQ> ref;

            enum Type { Get, Set, Result, Error };

            IQ(Type type = Get) : type_(type) { }

            Type getType() const { return type_; }
            void setType(Type type) { type_ = type; }

            static std::shared_ptr<IQ> createRequest(
                    Type type,
                    const JID& to,
                    const std::string& id,
                    std::shared_ptr<Payload> payload);
            static std::shared_ptr<IQ> createResult(
                    const JID& to,
                    const std::string& id,
                    std::shared_ptr<Payload> payload = std::shared_ptr<Payload>());
            static std::shared_ptr<IQ> createResult(
                    const JID& to,
                    const JID& from,
                    const std::string& id,
                    std::shared_ptr<Payload> payload = std::shared_ptr<Payload>());
            static std::shared_ptr<IQ> createError(
                    const JID& to,
                    const std::string& id,
                    ErrorPayload::Condition condition = ErrorPayload::BadRequest,
                    ErrorPayload::Type type = ErrorPayload::Cancel,
                    std::shared_ptr<Payload> payload = std::shared_ptr<Payload>());
            static std::shared_ptr<IQ> createError(
                    const JID& to,
                    const JID& from,
                    const std::string& id,
                    ErrorPayload::Condition condition = ErrorPayload::BadRequest,
                    ErrorPayload::Type type = ErrorPayload::Cancel,
                    std::shared_ptr<Payload> payload = std::shared_ptr<Payload>());

        private:
            Type type_;
    };
}

#endif // JXMPP_IQ_H
