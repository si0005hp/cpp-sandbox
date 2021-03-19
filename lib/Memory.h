#pragma once

#include "../all.h"

namespace lib
{

class Memory
{
  public:
    static inline void* allocate(size_t size)
    {
        std::cout << "[Memory] Allocated " << size << " bytes" << std::endl;
        return reallocate(nullptr, 0, size);
    }

    template <typename T>
    static inline void* freeObj(T* pointer)
    {
        std::cout << "[Memory] Free " << sizeof(T) << " bytes" << std::endl;
        return reallocate(nullptr, sizeof(T), 0);
    }

    static inline void* free(void* pointer, size_t size)
    {
        std::cout << "[Memory] Free " << size << " bytes" << std::endl;
        return reallocate(nullptr, size, 0);
    }

  private:
    static inline void* reallocate(void* pointer, size_t oldSize,
                                   size_t newSize)
    {
        totalBytesAllocated_ += newSize - oldSize;

        if (newSize <= 0)
        {
            std::free(pointer);
            return NULL;
        }

        void* result = realloc(pointer, newSize);
        if (result == NULL) exit(1);

        return result;
    }

    static inline size_t totalBytesAllocated_;
};

} // namespace lib
