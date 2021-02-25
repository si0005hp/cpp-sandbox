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

namespace Address
{

class Item
{
  public:
    Item(const string &name) : mName(name)
    {
    }
    void Print() const
    {
        cout << "Item: " << mName << endl;
    }

    string mName;
};

void UpdateR(Item &item)
{
    item.mName = "Updated";
}

void UpdateP(Item *item)
{
    // item->mName = "Updated";
    Item i = *item;
    i.mName = "Updated";
}

void ShowAddressR(Item &item)
{
    cout << &item << endl;
}

void run()
{
    Item *item = new Item("one");
    // item->Print();
    // UpdateR(*item);
    // item->Print();
    cout << item << endl;
    ShowAddressR(*item);
}

class AddressHolder
{
  public:
    void Add(const shared_ptr<Item> &addr, const string &value)
    {
        mAddrMap[addr] = value;
    }
    void PrintAll()
    {
        for (auto &[k, v] : mAddrMap)
            cout << k << ":" << v << endl;
    }

    unordered_map<shared_ptr<Item>, string> mAddrMap;
};

void AddToHolder(AddressHolder &h, const shared_ptr<Item> &item)
{
    // h.Add(make_shared<Item>(item), item.mName);
    h.Add(item, item->mName);
}

void run2()
{
    AddressHolder h;

    auto sp1 = make_shared<Item>("a");
    cout << sp1 << endl;

    AddToHolder(h, sp1);
    h.PrintAll();
}

} // namespace Address

} // namespace pointer
int main(int argc, char const *argv[])
{
    // pointer::NullCheck::run();
    // pointer::Polymorphism::run();
    pointer::Address::run2();
    return 0;
}
