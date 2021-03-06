#include "all.h"

using namespace std;

namespace Inheritance
{

class Base
{
  public:
    virtual void print() { cout << "Base" << endl; }
};

class Derived1 : public Base
{
  public:
    virtual void print() override
    {
        Base::print();
        cout << "Derived" << endl;
    }
};

void run()
{
    Base *b = new Derived1();
    b->print();
}

} // namespace Inheritance

int main(int argc, char const *argv[])
{
    Inheritance::run();
    return 0;
}
