#include "../all.h"

using namespace std;

namespace EffectiveCpp_3
{

class Item
{
  public:
    Item(const string &name) : mName(name)
    {
    }
    void Print()
    {
        cout << "Item: " << mName << endl;
    }
    void Print() const
    {
        cout << "(const) Item: " << mName << endl;
    }

    void LogicallyNotConstMethod_UpdatePointer(Item *item) const
    {
        item->mName = "mistakenly-updated-pointer";
    }
    void LogicallyNotConstMethod_UpdateReference(Item &item) const
    {
        item.mName = "mistakenly-updated-reference";
    }

    string mName;
};

void PrintItem(Item &i)
{
    i.Print();
}

void run()
{
    cout << "--- [1 object] ---" << endl;

    Item item("aaa");
    const Item constItem("bbb");

    cout << "--- [2 pointer] ---" << endl;

    Item *itemPointer1 = &item;
    // Item *itemPointer2 = &constItem; NG

    const Item *constItem_Pointer1 = &item;
    const Item *constItem_Pointer2 = &constItem;

    Item *const item_constPointer1 = &item;
    // Item *const item_constPointer2 = &constItem; NG

    const Item *const constItem_constPointer1 = &item;
    const Item *const constItem_constPointer2 = &constItem;

    // constItem_Pointer1->mName = "xxx"; NG
    constItem_Pointer1 = &constItem;

    // item_constPointer1 = constItem; NG
    item_constPointer1->mName = "xxx";

    // constItem_constPointer1 = &constItem; NG
    // constItem_constPointer1->mName = "xxx";

    cout << "--- [3 ref] ---" << endl;

    Item &itemRef = item;
    // Item &itemRef2 = constItem; NG

    const Item &constItem_Ref = item;
    const Item &constItem_Ref2 = constItem;

    // constItem.mName = "xxx"; NG

    cout << "--- [4 method] ---" << endl;
    Item updater("");

    Item i1("one");
    Item i2("two");

    updater.LogicallyNotConstMethod_UpdatePointer(&i1);
    updater.LogicallyNotConstMethod_UpdateReference(i2);

    i1.Print();
    i2.Print();
}

} // namespace EffectiveCpp_3

int main(int argc, char const *argv[])
{
    EffectiveCpp_3::run();
    return 0;
}
