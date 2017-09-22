#include <JXMPP/Base/Debug.h>

#include <iostream>
#include <memory>

#include <JXMPP/Client/ClientError.h>
#include <JXMPP/Client/ClientSession.h>
#include <JXMPP/Serializer/PayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/FullPayloadSerializerCollection.h>
#include <JXMPP/Serializer/XMPPSerializer.h>

std::ostream& operator<<(std::ostream& os, const JXMPP::ClientError& error) {
    os << "ClientError(";
    switch(error.getType()) {
        case JXMPP::ClientError::UnknownError:
            os << "UnknownError";
            break;
        case JXMPP::ClientError::DomainNameResolveError:
            os << "DomainNameResolveError";
            break;
        case JXMPP::ClientError::ConnectionError:
            os << "ConnectionError";
            break;
        case JXMPP::ClientError::ConnectionReadError:
            os << "ConnectionReadError";
            break;
        case JXMPP::ClientError::ConnectionWriteError:
            os << "ConnectionWriteError";
            break;
        case JXMPP::ClientError::XMLError:
            os << "XMLError";
            break;
        case JXMPP::ClientError::AuthenticationFailedError:
            os << "AuthenticationFailedError";
            break;
        case JXMPP::ClientError::CompressionFailedError:
            os << "CompressionFailedError";
            break;
        case JXMPP::ClientError::ServerVerificationFailedError:
            os << "ServerVerificationFailedError";
            break;
        case JXMPP::ClientError::NoSupportedAuthMechanismsError:
            os << "NoSupportedAuthMechanismsError";
            break;
        case JXMPP::ClientError::UnexpectedElementError:
            os << "UnexpectedElementError";
            break;
        case JXMPP::ClientError::ResourceBindError:
            os << "ResourceBindError";
            break;
        case JXMPP::ClientError::SessionStartError:
            os << "SessionStartError";
            break;
        case JXMPP::ClientError::StreamError:
            os << "StreamError";
            break;
        case JXMPP::ClientError::TLSError:
            os << "TLSError";
            break;
        case JXMPP::ClientError::ClientCertificateLoadError:
            os << "ClientCertificateLoadError";
            break;
        case JXMPP::ClientError::ClientCertificateError:
            os << "ClientCertificateError";
            break;
        case JXMPP::ClientError::CertificateCardRemoved:
            os << "CertificateCardRemoved";
            break;
        case JXMPP::ClientError::UnknownCertificateError:
            os << "UnknownCertificateError";
            break;
        case JXMPP::ClientError::CertificateExpiredError:
            os << "CertificateExpiredError";
            break;
        case JXMPP::ClientError::CertificateNotYetValidError:
            os << "CertificateNotYetValidError";
            break;
        case JXMPP::ClientError::CertificateSelfSignedError:
            os << "CertificateSelfSignedError";
            break;
        case JXMPP::ClientError::CertificateRejectedError:
            os << "CertificateRejectedError";
            break;
        case JXMPP::ClientError::CertificateUntrustedError:
            os << "CertificateUntrustedError";
            break;
        case JXMPP::ClientError::InvalidCertificatePurposeError:
            os << "InvalidCertificatePurposeError";
            break;
        case JXMPP::ClientError::CertificatePathLengthExceededError:
            os << "CertificatePathLengthExceededError";
            break;
        case JXMPP::ClientError::InvalidCertificateSignatureError:
            os << "InvalidCertificateSignatureError";
            break;
        case JXMPP::ClientError::InvalidCAError:
            os << "InvalidCAError";
            break;
        case JXMPP::ClientError::InvalidServerIdentityError:
            os << "InvalidServerIdentityError";
            break;
        case JXMPP::ClientError::RevokedError:
            os << "RevokedError";
            break;
        case JXMPP::ClientError::RevocationCheckFailedError:
            os << "RevocationCheckFailedError";
            break;
    }
    os << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, JXMPP::Element* ele) {
    using namespace JXMPP;

    std::shared_ptr<Element> element = std::shared_ptr<Element>(ele);

    std::shared_ptr<Payload> payload = std::dynamic_pointer_cast<Payload>(element);
    if (payload) {
         FullPayloadSerializerCollection payloadSerializerCollection;
         PayloadSerializer *serializer = payloadSerializerCollection.getPayloadSerializer(payload);
         os << "Payload(" << serializer->serialize(payload) << ")";
         return os;
    }
    std::shared_ptr<ToplevelElement> topLevelElement = std::dynamic_pointer_cast<ToplevelElement>(element);
    if (topLevelElement) {
        FullPayloadSerializerCollection payloadSerializerCollection;
        XMPPSerializer xmppSerializer(&payloadSerializerCollection, ClientStreamType, false);
        SafeByteArray serialized = xmppSerializer.serializeElement(topLevelElement);
        os << "TopLevelElement(" << safeByteArrayToString(serialized) << ")";
        return os;
    }
    os << "Element(Unknown)";
    return os;
}

std::ostream& operator<<(std::ostream& os, JXMPP::ClientSession::State state) {
    using CS = JXMPP::ClientSession;
    switch (state) {
        case CS::State::Initial:
            os << "ClientSession::State::Initial";
            break;
        case CS::State::WaitingForStreamStart:
            os << "ClientSession::State::WaitingForStreamStart";
            break;
        case CS::State::Negotiating:
            os << "ClientSession::State::Negotiating";
            break;
        case CS::State::Compressing:
            os << "ClientSession::State::Compressing";
            break;
        case CS::State::WaitingForEncrypt:
            os << "ClientSession::State::WaitingForEncrypt";
            break;
        case CS::State::Encrypting:
            os << "ClientSession::State::Encrypting";
            break;
        case CS::State::WaitingForCredentials:
            os << "ClientSession::State::WaitingForCredentials";
            break;
        case CS::State::Authenticating:
            os << "ClientSession::State::Authenticating";
            break;
        case CS::State::EnablingSessionManagement:
            os << "ClientSession::State::EnablingSessionManagement";
            break;
        case CS::State::BindingResource:
            os << "ClientSession::State::BindingResource";
            break;
        case CS::State::StartingSession:
            os << "ClientSession::State::StartingSession";
            break;
        case CS::State::Initialized:
            os << "ClientSession::State::Initialized";
            break;
        case CS::State::Finishing:
            os << "ClientSession::State::Finishing";
            break;
        case CS::State::Finished:
            os << "ClientSession::State::Finished";
            break;
    }
    return os;
}
