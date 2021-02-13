#include "all.h"

using namespace std;

namespace object
{
class Item
{
  public:
    Item(const string &name, const int &price) : mName(name), mPrice(price)
    {
    }
    void Print()
    {
        cout << "[Item] " << mName << " " << mPrice << "$" << endl;
    }

    string mName;
    int mPrice;
};

Item MakeItem(const string &name, const int &price)
{
    return Item(name, price);
}

// NG
const Item &MakeItem2(const string &name, const int &price)
{
    return Item(name, price);
}

Item &MakeItem3(const string &name, const int &price)
{
    Item *i = new Item(name, price);
    return *i;
}

} // namespace object

using namespace object;

int main(int argc, char const *argv[])
{
    Item i = MakeItem3("a", 100);
    i.Print();
    return 0;
}
