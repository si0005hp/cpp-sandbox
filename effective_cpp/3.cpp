#include "../all.h"

using namespace std;

namespace EffectiveCpp_3
{

class Item
{
  public:
    Item(const string &name) : mName(name) {}

    void Print() { cout << "Item: " << mName << endl; }
    void Print() const { cout << "(const) Item: " << mName << endl; }

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
}

namespace BitLevelConst_LogicallyConst
{

class BitLevelConstText
{
  public:
    BitLevelConstText(const string &text)
    {
        text_ = new char[text.length() + 1];
        strcpy(text_, text.c_str());
    }

    char &operator[](size_t position) const { return text_[position]; }

    void print() const { cout << text_ << endl; }

  private:
    char *text_;
};

class LogicallyConstText
{
  public:
    LogicallyConstText(const string &text)
    {
        text_ = new char[text.length() + 1];
        strcpy(text_, text.c_str());
    }

    // illegal
    void incCount() const { printCalledCount++; }
    int getCount() const { return printCalledCount; }

  private:
    char *text_;
    mutable int printCalledCount = 0;
};

void run()
{
    const BitLevelConstText bct("Hello");
    char *c = &bct[0];
    *c = 'J';
    bct.print();

    cout << "-----" << endl;

    const LogicallyConstText lct("World");
    lct.incCount();
    lct.incCount();
    cout << lct.getCount() << endl;
}

} // namespace BitLevelConst_LogicallyConst

namespace ReuseConstWithinNonConst
{

class Text
{
  public:
    Text(const string &text)
    {
        text_ = new char[text.length() + 1];
        strcpy(text_, text.c_str());
    }

    void someMethod1() const {}
    void someMethod2() const {}
    void someMethod3() const {}

    const char &operator[](size_t position) const
    {
        someMethod1();
        someMethod2();
        someMethod3();
        return text_[position];
    }

    //   char &operator[](size_t position) {
    //     someMethod1();
    //     someMethod2();
    //     someMethod3();
    //     return text_[position];
    //   }

    char &operator[](size_t position)
    {
        auto &constText = static_cast<const Text &>(*this);
        return const_cast<char &>(constText[position]);
    }

  private:
    char *text_;
};

void run()
{
    Text t("aaa");
    const Text ct("bbb");

    cout << t[0] << endl;
    cout << ct[0] << endl;
}

} // namespace ReuseConstWithinNonConst

} // namespace EffectiveCpp_3

int main(int argc, char const *argv[])
{
    EffectiveCpp_3::run();
    EffectiveCpp_3::BitLevelConst_LogicallyConst::run();
    EffectiveCpp_3::ReuseConstWithinNonConst::run();
    return 0;
}
