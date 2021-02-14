#include "all.h"

using namespace std;

namespace pointer
{

namespace NullCheck
{
template <typename T> void CheckNullPtr(T *p, const string &name)
{
    if (p)
    {
        cout << name << " is NOT null ptr" << endl;
    }
    else
    {
        cout << name << " is null ptr" << endl;
    }
}

void run()
{
    int *i;
    CheckNullPtr(i, "*i");

    int *i2;
    i2 = nullptr;
    CheckNullPtr(i2, "*i2");

    shared_ptr<int> sp;
    CheckNullPtr(sp.get(), "sp.get()");

    shared_ptr<int> sp2;
    sp2 = nullptr;
    CheckNullPtr(sp2.get(), "sp2.get()");
}
} // namespace NullCheck

namespace Polymorphism
{
class Animal
{
  public:
    virtual void Cry() = 0;
};

class Dog : public Animal
{
  public:
    void Cry() override
    {
        cout << "Im a dog" << endl;
    }
};

class Cat : public Animal
{
  public:
    void Cry() override
    {
        cout << "Im a cat" << endl;
    }
};

void run()
{
    auto pa1 = new Dog();
    auto pa2 = new Cat();
    pa1->Cry();
    pa2->Cry();

    auto sa1 = make_shared<Dog>();
    auto sa2 = make_shared<Cat>();
    sa1->Cry();
    sa2->Cry();
}

} // namespace Polymorphism

} // namespace pointer
int main(int argc, char const *argv[])
{
    pointer::NullCheck::run();
    // pointer::Polymorphism::run();
    return 0;
}
