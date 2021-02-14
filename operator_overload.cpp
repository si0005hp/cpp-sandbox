#include "all.h"

using namespace std;

namespace operator_overload
{

class Animal
{
  public:
    virtual void Cry()
    {
        cout << "Im a Animal" << endl;
    }
    // virtual void Cry() = 0;

    virtual bool operator==(const Animal &other)
    {
        cout << "[Animal ==]" << endl;
        return true;
    }

    virtual bool operator==(const Animal &other) const
    {
        cout << "[const Animal ==]" << endl;
        return true;
    }
}; // namespace operator_overload

class Dog : public Animal
{
  public:
    void Cry() override
    {
        cout << "Im a dog" << endl;
    }
    bool operator==(const Animal &other)
    {
        cout << "[Dog ==]" << endl;
        return true;
    }

    bool operator==(const Animal &other) const
    {
        cout << "[const Dog ==]" << endl;
        return true;
    }
};

class Cat : public Animal
{
  public:
    void Cry() override
    {
        cout << "Im a cat" << endl;
    }
    bool operator==(const Animal &other)
    {
        cout << "[Cat ==]" << endl;
        return true;
    }

    bool operator==(const Animal &other) const
    {
        cout << "[const Cat ==]" << endl;
        return true;
    }
};

void run()
{
    // Animal *a1 = new Dog();
    Animal *a1 = new Dog();
    Animal *a2 = new Dog();

    a1->Cry();
    Animal a = *a1;
    a.Cry();
}

} // namespace operator_overload

using namespace operator_overload;

int main(int argc, char const *argv[])
{
    operator_overload::run();
    return 0;
}
