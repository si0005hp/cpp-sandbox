#include "all.h"

using namespace std;

namespace Const
{

class Item
{
  public:
    Item(const string &name) : mName(name) {}
    void Print() { cout << "Item: " << mName << endl; }

    const Item *GetCP() const { return this; }
    const Item &GetCR() const { return *this; }

    string mName;
};

void run()
{
    Item a("aaa");

    // auto i = a.GetCP();
    // i->Print(); // NG

    // auto &i = a.GetCR();
    // i.Print(); // NG

    auto i = a.GetCR();
    i.Print(); // OK (mistakenly)
}

} // namespace Const

int main(int argc, char const *argv[])
{
    Const::run();
    return 0;
}
