#include "../all.h"

using namespace std;

namespace EffectiveCpp_7
{

class Item
{
  public:
    Item(const string &name) : mName(name) {}
    // virtual ~Item() {}

    virtual void Print() = 0;

    string mName;
};

class Apple : public Item
{
  public:
    Apple(const string &name) : Item(name) {}
    ~Apple() { cout << "Apple destructor" << endl; }

    void Print() { cout << "Apple:" << mName << endl; }
};

class Banana : public Item
{
  public:
    Banana(const string &name) : Item(name) {}
    ~Banana() { cout << "Banana destructor" << endl; }

    void Print() { cout << "Banana:" << mName << endl; }
};

void run()
{
    {
        Item *item = new Apple("a");
        delete item;
    }

    cout << "-----" << endl;

    {
        auto item = make_unique<Apple>("a");
    }
}

} // namespace EffectiveCpp_7

int main(int argc, char const *argv[])
{
    EffectiveCpp_7::run();
    return 0;
}
