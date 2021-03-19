#include <new>

#include "Memory.h"

namespace lib
{

template <class T>
struct MyAllocator
{
    using value_type = T;

    MyAllocator() {}

    template <class U>
    MyAllocator(const MyAllocator<U>&)
    {
    }

    T* allocate(std::size_t n)
    {
        return reinterpret_cast<T*>(Memory::allocate(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) { Memory::free(p, n * sizeof(T)); }
};

template <class T, class U>
bool operator==(const MyAllocator<T>&, const MyAllocator<U>&)
{
    return true;
}

template <class T, class U>
bool operator!=(const MyAllocator<T>&, const MyAllocator<U>&)
{
    return false;
}

} // namespace lib
