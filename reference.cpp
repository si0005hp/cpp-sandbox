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

    const Message &Get()
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
    Message m("hi there");
    SendMessage(m.Get());
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

int main(int argc, char const *argv[])
{
    // Reference::run();
    // RValue::run();
    ReferenceField::run();
    return 0;
}
