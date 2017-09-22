#ifndef JXMPP_HASHELEMENT_H
#define JXMPP_HASHELEMENT_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>

namespace JXMPP {
    /*
     * @brief This class represents a XEP-0300 <hash/> element.
     */
    class JXMPP_API HashElement {
        public:
            HashElement(const std::string& algorithm, const ByteArray& hash) : algorithm_(algorithm), hash_(hash) {
            }

            void setHashValue(const std::string& algorithm, const ByteArray& hash) {
                algorithm_ = algorithm;
                hash_ = hash;
            }

            const std::string& getAlgorithm() const {
                return algorithm_;
            }

            const ByteArray& getHashValue() const {
                return hash_;
            }

            bool operator==(const HashElement& rhs) const {
                return (algorithm_ == rhs.algorithm_) && (hash_ == rhs.hash_);
            }


        private:
            std::string algorithm_;
            ByteArray hash_;
    };
}

#endif // JXMPP_HASHELEMENT_H
