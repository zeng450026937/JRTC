#include <JXMPP/Disco/CapsInfoGenerator.h>

#include <algorithm>

#include <JXMPP/Crypto/CryptoProvider.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Elements/FormField.h>
#include <JXMPP/StringCodecs/Base64.h>

namespace {
    bool compareFields(JXMPP::FormField::ref f1, JXMPP::FormField::ref f2) {
        return f1->getName() < f2->getName();
    }
}

namespace JXMPP {

CapsInfoGenerator::CapsInfoGenerator(const std::string& node, CryptoProvider* crypto) : node_(node), crypto_(crypto) {
}

CapsInfo CapsInfoGenerator::generateCapsInfo(const DiscoInfo& discoInfo) const {
    std::string serializedCaps;

    std::vector<DiscoInfo::Identity> identities(discoInfo.getIdentities());
    std::sort(identities.begin(), identities.end());
    for (const auto& identity : identities) {
        serializedCaps += identity.getCategory() + "/" + identity.getType() + "/" + identity.getLanguage() + "/" + identity.getName() + "<";
    }

    std::vector<std::string> features(discoInfo.getFeatures());
    std::sort(features.begin(), features.end());
    for (const auto& feature : features) {
        serializedCaps += feature + "<";
    }

    for (const auto& extension : discoInfo.getExtensions()) {
        serializedCaps += extension->getFormType() + "<";
        std::vector<FormField::ref> fields(extension->getFields());
        std::sort(fields.begin(), fields.end(), &compareFields);
        for (const auto& field : fields) {
            if (field->getName() == "FORM_TYPE") {
                continue;
            }
            serializedCaps += field->getName() + "<";
            std::vector<std::string> values(field->getValues());
            std::sort(values.begin(), values.end());
            for (const auto& value : values) {
                serializedCaps += value + "<";
            }
        }
    }

    std::string version(Base64::encode(crypto_->getSHA1Hash(createByteArray(serializedCaps))));
    return CapsInfo(node_, version, "sha-1");
}

}
