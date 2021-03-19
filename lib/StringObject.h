#pragma once

#include "../all.h"

namespace lib
{

class StringObject
{
  public:

  private:
    int length_;
    char* chars_;
    uint32_t hash_;
};

} // namespace lib
