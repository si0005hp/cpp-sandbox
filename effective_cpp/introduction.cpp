#include "../all.h"

using namespace std;

namespace EffectiveCpp_Intruduction
{

namespace Explicit
{

class Num
{
  public:
    Num(int val) : mVal(val) {}

    int mVal;
};

class Pair
{
  public:
    Pair(int a, int b = 0) : mA(a), mB(b) {}

    int mA;
    int mB;
};

class ExplicitNum
{
  public:
    explicit ExplicitNum(int val) : mVal(val) {}

    int mVal;
};

class ExplicitPair
{
  public:
    explicit ExplicitPair(int a, int b = 0) : mA(a), mB(b) {}

    int mA;
    int mB;
};

void withNum(Num num)
{
    cout << num.mVal << endl;
}
void withExplicitNum(ExplicitNum num)
{
    cout << num.mVal << endl;
}

void run()
{
    Num n1 = 1;
    Pair p1 = 10;
    withNum(100);

    // ExplicitNum n2 = 1;
    // ExplicitPair p2 = 10;
    // withExplicitNum(100);
}

} // namespace Explicit

namespace Construcor
{
class Widget
{
  public:
    Widget() { cout << "default constructor is called" << endl; }
    Widget(const Widget &rhs) { cout << "copy constructor is called" << endl; }
    Widget &operator=(const Widget &rhs)
    {
        cout << "copy assign operator is called" << endl;
    }
};

void run()
{
    Widget w1;
    Widget w2(w1);
    Widget w3 = w1;
    w1 = w2;
}
} // namespace Construcor

} // namespace EffectiveCpp_Intruduction

int main(int argc, char const *argv[])
{
    EffectiveCpp_Intruduction::Explicit::run();
    cout << "----------" << endl;
    EffectiveCpp_Intruduction::Construcor::run();
    return 0;
}
