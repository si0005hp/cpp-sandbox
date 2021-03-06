#include "all.h"

using namespace std;

namespace object
{
class Item
{
  public:
    Item(const string &name, const int &price) : mName(name), mPrice(price) {}
    void Print() { cout << "[Item] " << mName << " " << mPrice << "$" << endl; }

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

namespace object2
{

class Database
{
  public:
    Database() {}
    Database(const vector<string> &values) : mValues(values) {}
    void Add(const string &value) { mValues.push_back(value); }

    const vector<string> &GetValues() const { return mValues; }

    vector<string> mValues;
};

void run()
{
    const vector<string> &values = {"a", "b"};
    Database d(values);

    const vector<string> &got_values = d.GetValues();

    d.Add("c");

    for (auto v : got_values)
    {
        cout << v << endl;
    }
}

} // namespace object2

namespace object3
{

class SomeValue
{
  public:
    SomeValue() : mStr(""), mNum(0) {}
    SomeValue(const string &s, const int &n) : mStr(s), mNum(n) {}
    void Show() const { cout << mStr << ":" << mNum << endl; }
    string mStr;
    int mNum;
};

class SomeObject
{
  public:
    SomeObject() {}
    void UpdateStr(const string &s) { mValue.mStr = s; }
    void UpdateNum(const int &n) { mValue.mNum = n; }
    void Show() { mValue.Show(); }

    const SomeValue &GetCValue() const { return mValue; }

    SomeValue mValue;
};

void run()
{
    SomeObject o;
    const SomeValue &v = o.GetCValue();
    // SomeValue v = o.GetCValue(); NG

    o.UpdateNum(999);
    o.UpdateStr("aaa");

    v.Show();

    o.UpdateNum(10000);
    o.UpdateStr("vvv");

    v.Show();
}

} // namespace object3

namespace nest
{

class Env
{
  public:
    Env() : mParent(nullptr) {}
    Env(const shared_ptr<Env> &parent) : mParent(parent) {}
    void Add(int k, string v) { mValues[k] = v; }
    string Get(int k)
    {
        if (mValues.contains(k))
            return mValues[k];

        if (mParent)
            return "@" + mParent->Get(k);

        throw runtime_error("no item: " + to_string(k));
    }

    unordered_map<int, string> mValues;
    shared_ptr<Env> mParent;
};

} // namespace nest

using namespace object;
using namespace object2;
using namespace object3;
using namespace nest;

int main(int argc, char const *argv[])
{
    auto root = make_shared<Env>();
    root->Add(1, "one");

    auto nest1 = make_shared<Env>(root);
    cout << nest1->Get(1) << endl;

    auto nest1_2 = make_shared<Env>(root);
    cout << nest1_2->Get(1) << endl;

    auto nest2 = make_shared<Env>(nest1);
    cout << nest2->Get(1) << endl;

    return 0;
}
