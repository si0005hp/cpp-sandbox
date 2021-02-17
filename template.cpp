#include "all.h"

using namespace std;

namespace Template
{

using namespace std;

class Value
{
  public:
};

class String : public Value
{
  public:
    String(const string &value) : mValue(value)
    {
    }
    string mValue;
};

class Number : public Value
{
  public:
    Number(const double &value) : mValue(value)
    {
    }
    double mValue;
};

template <typename T> T DynamicCast(Value &value)
{
    T &v = dynamic_cast<T &>(value);
    return v;
}

void run()
{
    String s("a");
    Value &v = s;
    String &s2 = dynamic_cast<String &>(v);

    // Value v2 = Number(12);

    // String s = DynamicCast<String>(v1);
    // DynamicCast(v2);
}

} // namespace Template

int main(int argc, char const *argv[])
{
    Template::run();
    return 0;
}
