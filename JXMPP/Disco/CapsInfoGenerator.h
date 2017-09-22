#ifndef JXMPP_CAPSINFOGENERATOR_H
#define JXMPP_CAPSINFOGENERATOR_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CapsInfo.h>

namespace JXMPP {
    class DiscoInfo;
    class CryptoProvider;

    class JXMPP_API CapsInfoGenerator {
        public:
            CapsInfoGenerator(const std::string& node, CryptoProvider* crypto);

            CapsInfo generateCapsInfo(const DiscoInfo& discoInfo) const;

        private:
            std::string node_;
            CryptoProvider* crypto_;
    };
}

#endif // JXMPP_CAPSINFOGENERATOR_H
