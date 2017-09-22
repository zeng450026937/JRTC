#ifndef JXMPP_STREAMERROR_H
#define JXMPP_STREAMERROR_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API StreamError : public ToplevelElement {
        public:
            typedef std::shared_ptr<StreamError> ref;

            enum Type {
                BadFormat,
                BadNamespacePrefix,
                Conflict,
                ConnectionTimeout,
                HostGone,
                HostUnknown,
                ImproperAddressing,
                InternalServerError,
                InvalidFrom,
                InvalidID,
                InvalidNamespace,
                InvalidXML,
                NotAuthorized,
                NotWellFormed,
                PolicyViolation,
                RemoteConnectionFailed,
                Reset,
                ResourceConstraint,
                RestrictedXML,
                SeeOtherHost,
                SystemShutdown,
                UndefinedCondition,
                UnsupportedEncoding,
                UnsupportedStanzaType,
                UnsupportedVersion
            };

            StreamError(Type type = UndefinedCondition, const std::string& text = std::string()) : type_(type), text_(text) { }

            Type getType() const {
                return type_;
            }

            void setType(Type type) {
                type_ = type;
            }

            void setText(const std::string& text) {
                text_ = text;
            }

            const std::string& getText() const {
                return text_;
            }

        private:
            Type type_;
            std::string text_;
    };
}

#endif // JXMPP_STREAMERROR_H
