#include "all.h"

using namespace std;

namespace Template
{

using namespace std;

class Value
{
  public:
    template <typename T>
    T As();
};

class String : public Value
{
  public:
    String(const string &value) : mValue(value) {}

    template <typename T>
    T As()
    {
        return mValue;
    }

    string mValue;
};

class Number : public Value
{
  public:
    Number(const double &value) : mValue(value) {}

    template <typename T>
    T As()
    {
        return mValue;
    }

    double mValue;
};

template <typename T>
T DynamicCast(Value &value)
{
    T &v = dynamic_cast<T &>(value);
    return v;
}

void run()
{
    // String s("a");
    Value *v = new String("a");
    v->As<string>();
    // String &s2 = dynamic_cast<String &>(v);

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
