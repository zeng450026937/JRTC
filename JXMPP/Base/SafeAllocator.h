#ifndef JXMPP_SAFEALLOCATOR_H
#define JXMPP_SAFEALLOCATOR_H

#include <algorithm>
#include <vector>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    JXMPP_API void secureZeroMemory(char* memory, size_t numberOfBytes);

    template<typename T>
    class JXMPP_API SafeAllocator : public std::allocator<T> {
        public:
            template <class U> struct rebind {
                typedef SafeAllocator<U> other;
            };

            SafeAllocator() JXMPP_NOEXCEPT {}
            SafeAllocator(const SafeAllocator&) JXMPP_NOEXCEPT : std::allocator<T>() {}
            template <class U> SafeAllocator(const SafeAllocator<U>&) JXMPP_NOEXCEPT {}
            ~SafeAllocator() JXMPP_NOEXCEPT {}

            void deallocate (T* p, size_t num) {
                secureZeroMemory(reinterpret_cast<char*>(p), num);
                std::allocator<T>::deallocate(p, num);
            }

            JXMPP_DEFAULT_COPY_ASSIGMNENT_OPERATOR(SafeAllocator)
    };
}

#endif // JXMPP_SAFEALLOCATOR_H
