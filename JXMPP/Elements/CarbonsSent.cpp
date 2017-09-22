#include <JXMPP/Elements/CarbonsSent.h>

namespace JXMPP {
    CarbonsSent::~CarbonsSent() {

    }

    void CarbonsSent::setForwarded(std::shared_ptr<Forwarded> forwarded) {
        forwarded_ = forwarded;
    }

    std::shared_ptr<Forwarded> CarbonsSent::getForwarded() const {
        return forwarded_;
    }
}
