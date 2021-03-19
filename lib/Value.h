#pragma once

#include "../all.h"

namespace lib
{

class Value
{
  public:
    /* Number */
    explicit Value(double number);
    double AsNumber() const;

    /* String */
    explicit Value(const std::string& str);
    double AsString() const;

  private:
    uint64_t value_;
};

} // namespace lib
