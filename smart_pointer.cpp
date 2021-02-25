#include "all.h"

using namespace std;

namespace smart_pointer
{

namespace Nullptr
{

void CheckNull(shared_ptr<int> p)
{
    if (p)
    {
        cout << "NOT null (value: " << *p << ")" << endl;
    }
    else
    {
        cout << "null" << endl;
    }
}

void run()
{
    shared_ptr<int> i1 = make_shared<int>(1);
    shared_ptr<int> i2 = nullptr;
    shared_ptr<int> i3;

    CheckNull(i1);
    CheckNull(i2);
    CheckNull(i3);
}
} // namespace Nullptr

namespace NestedPtr
{

class Item
{
  public:
    Item(const string &name) : mName(name)
    {
    }
    string mName;
};

template <typename T> class Database
{
  public:
    void add(T item)
    {
        mItems.push_back(item);
    }

    vector<T> mItems;
};

void MemLeak1(int itemCount)
{
    Database<Item *> db;
    for (int i = 0; i < itemCount; i++)
        db.add(new Item(to_string(itemCount)));
}

void MemLeak2(int itemCount)
{
    auto db = make_shared<Database<Item *>>();
    for (int i = 0; i < itemCount; i++)
        db->add(new Item(to_string(itemCount)));
}

void MemLeak3(int itemCount)
{
    auto db = new Database<shared_ptr<Item>>();
    for (int i = 0; i < itemCount; i++)
        db->add(make_shared<Item>(to_string(itemCount)));
}

void NoMemLeak1(int itemCount)
{
    Database<shared_ptr<Item>> db;
    for (int i = 0; i < itemCount; i++)
        db.add(make_shared<Item>(to_string(itemCount)));
}

void NoMemLeak2(int itemCount)
{
    auto db = make_shared<Database<shared_ptr<Item>>>();
    for (int i = 0; i < itemCount; i++)
        db->add(make_shared<Item>(to_string(itemCount)));
}

void run()
{
    while (true)
    {
        NoMemLeak2(10000);
        sleep(1);
        cout << "running..." << endl;
    }
}

} // namespace NestedPtr

namespace UniquePtr
{

void run()
{
    unique_ptr<int> i = make_unique<int>(1);
    unique_ptr<int> i2 = std::move(i);

    cout << *i << endl;
}

} // namespace UniquePtr

namespace Const
{

class Item
{
  public:
    Item(const string &name) : mName(name)
    {
    }
    void Mod(const string &name)
    {
        mName = name;
    }
    void Print() const
    {
        cout << mName << endl;
    }

    string mName;
};

class ItemHolder
{
  public:
    ItemHolder()
    {
    }
    ItemHolder(const shared_ptr<Item> &mItem) : mItem(mItem)
    {
    }
    const shared_ptr<Item> &GetItem() const
    {
        return mItem;
    }
    const Item &GetCItem() const
    {
        return *mItem;
    }

    shared_ptr<Item> mItem;
};

void run()
{
    auto item = make_shared<Item>("aaa");
    ItemHolder h(item);

    // auto i = h.GetItem();
    // i->Mod("a");
    // i->Print();

    auto &ci = h.GetCItem();
    // ci.Mod("a");
    ci.Print();
}

void run2()
{
    // ItemHolder h;
    // auto &item = h.GetCItem();

    // string s = item.mName;
    // // cout << item.mName << endl;

    shared_ptr<int> i = nullptr;
    *i;
}

} // namespace Const

namespace Ref
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

class Database
{
  public:
    void AddItem(const shared_ptr<Item> &item)
    {
        mItems.push_back(item);
    }
    void Print() const
    {
        for (auto item : mItems)
            item->Print();
    }

    vector<shared_ptr<Item>> mItems;
};

void AddItems(Database &db)
{
    auto a = make_shared<Item>("a");
    db.AddItem(a);
    auto b = make_shared<Item>("b");
    db.AddItem(b);
}

void run()
{
    Database db;
    AddItems(db);

    db.Print();
}
} // namespace Ref

} // namespace smart_pointer
int main(int argc, char const *argv[])
{
    // smart_pointer::NestedPtr::run();
    // smart_pointer::Nullptr::run();
    // smart_pointer::UniquePtr::run();
    // smart_pointer::Const::run2();
    smart_pointer::Ref::run();
    return 0;
}
