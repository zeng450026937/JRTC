#ifndef JXMPP_ATOMIC_H
#define JXMPP_ATOMIC_H

#include <mutex>

namespace JXMPP {

/**
 * This class template provides a read/write access synchronized wrapper for other types.
 */
template <typename ValueType>
class Atomic {
    public:
        Atomic(const ValueType& v) : value_(v) {
        }

        /**
         * Synchronized write access.
         */
        Atomic<ValueType>& operator=(const ValueType& newValue) {
            std::lock_guard<std::mutex> lock(valueMutex_);
            value_ = newValue;
            return *this;
        }

        /**
         * Synchronized read access.
         */
        operator ValueType() {
            std::lock_guard<std::mutex> lock(valueMutex_);
            return value_;
        }

    private:
        std::mutex valueMutex_;
        ValueType value_;
};

}

#endif // JXMPP_ATOMIC_H
