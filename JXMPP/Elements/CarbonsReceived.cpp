#include <JXMPP/Elements/CarbonsReceived.h>

namespace JXMPP {
    CarbonsReceived::~CarbonsReceived() {

    }

    void CarbonsReceived::setForwarded(std::shared_ptr<Forwarded> forwarded) {
        forwarded_ = forwarded;
    }

    std::shared_ptr<Forwarded> CarbonsReceived::getForwarded() const {
        return forwarded_;
    }
}
