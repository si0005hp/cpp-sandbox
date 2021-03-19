#pragma once

#include "../all.h"
#include "Memory.h"

namespace lib
{

class Managed
{
  public:
    void* operator new(size_t size) { return Memory::allocate(size); }
};

} // namespace lib
