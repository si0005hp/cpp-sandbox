#include "all.h"

using namespace std;

namespace Reference
{

class Message
{
  public:
    Message(const string &msg) : mMsg(msg)
    {
    }
    void Print() const
    {
        cout << mMsg << endl;
    }

    const Message &Get() const
    {
        return *this;
    }
    Message &Get()
    {
        return *this;
    }

    string mMsg;
};

void SendMessage(const Message &msg)
{
    cout << "*** " << msg.mMsg << " ***" << endl;
}

void run()
{
    // Message m("hi there");
    // SendMessage(m.Get());

    Message m("hi there");
    cout << &m << endl;

    Message &mr = m;
    cout << &mr << endl;

    Message &mr2 = m.Get();
    cout << &mr2 << endl;

    // SendMessage(m.Get());
}

} // namespace Reference

namespace RValue
{

struct Data
{
    string title;
    int value;

    void Print()
    {
        cout << title << ":" << value << endl;
    }
};

class Obj
{
  public:
    Obj(Data &&data) : mData(std::move(data))
    {
    }

    void PrintData()
    {
        cout << mData.title << ":" << mData.value << endl;
    }
    Data &GetData()
    {
        return mData;
    }

  private:
    Data mData;
};

void P(shared_ptr<Data> const &dp)
{
    cout << dp->title << endl;
    cout << dp->value << endl;
}

void run()
{
    Data d{"a", 10};
    Obj o(std::move(d));
    o.PrintData();

    auto &data = o.GetData();
    data.title = "aaa";
    o.PrintData();

    // shared_ptr<Data> dp = make_shared<Data>(d);
    // auto a = *dp;
    // cout << a.title << endl;
    // cout << a.value << endl;
    // P(make_shared<Data>(d));
}

} // namespace RValue

namespace ReferenceField
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

class Bucket
{
  public:
    Bucket(const Item &item) : mItem(item)
    {
    }
    void Print() const
    {
        cout << "In the bucket, ";
        mItem.Print();
    }

    const Item &mItem;
};

// NG
Bucket Attach1(const string &name)
{
    Item i1(name);
    Bucket b1(i1);
    return b1;
}

Item *genItem(const string &name)
{
    return new Item(name);
}

Bucket Attach2(const string &name)
{
    // auto i1 = make_shared<Item>(name);

    // auto i1 = genItem(name);
    // Bucket b1(*i1);

    Bucket b1(*genItem(name));
    return b1;
}

void run()
{
    Bucket b1 = Attach2("aaa");
    b1.Print();
}

} // namespace ReferenceField

namespace AddressLifetime
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

unordered_map<int, shared_ptr<Item>> map;

void printMap()
{
    for (auto &[k, v] : map)
        cout << k << ":" << v->mName << endl;
}

void someProc(int i)
{
    shared_ptr<Item> item = nullptr;
    if (map.contains(i))
        item = map[i];

    if (item)
        cout << "someProc:\t" << &map[0]->mName << endl;
}

void run()
{
    for (size_t i = 0; i < 3; i++)
    {
        string s = "[" + to_string(i) + "]";
        auto item = make_shared<Item>(s);
        map[i] = item;
    }

    cout << "run:\t" << &map[0]->mName << endl;
    someProc(0);
}

} // namespace AddressLifetime

namespace Initializer
{

struct Data
{
    string title;
    int value;

    void Print()
    {
        cout << title << ":" << value << endl;
    }
};

class Item
{
  public:
    Item(Data &data) : mData(data)
    {
    }
    ~Item()
    {
        cout << "hi" << endl;
    }

    void Print() const
    {
        mData.Print();
    }

    Data &mData;
};

void run()
{
    Data data{"aaa", 999};

    // int i = 0;
    // Item item(data);
    new Item(data);

    // item.Print();
}

} // namespace Initializer

int main(int argc, char const *argv[])
{
    // Reference::run();
    // RValue::run();
    // AddressLifetime::run();
    Initializer::run();
    return 0;
}
