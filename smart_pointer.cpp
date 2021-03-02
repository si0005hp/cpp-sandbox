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

class Item : public enable_shared_from_this<Item>
{
  public:
    Item(const string &name) : mName(name)
    {
    }
    void Print() const
    {
        cout << "Item: " << mName << endl;
    }
    string Str() const
    {
        return "Item: " + mName;
    }

    shared_ptr<const Item> Ptr() const
    {
        return shared_from_this();
    }

    shared_ptr<Item> Ptr()
    {
        return shared_from_this();
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
    void AddItem(Item &item)
    {
        mItems.push_back(item.Ptr());
    }
    void Print() const
    {
        for (auto item : mItems)
            // item->Print();
            cout << "Print: " << item << " " << item->Str() << endl;
    }

    vector<shared_ptr<Item>> mItems;
};

void PrintDatabase(Database db)
{
    db.Print();
}

void AddItems(Database &db)
{
    auto a = make_shared<Item>("a");
    auto b = make_shared<Item>("b");

    // db.AddItem(a);
    // db.AddItem(b);
    db.AddItem(*a);
    db.AddItem(*b);

    cout << "AddItems a: " << a << endl;
    cout << "AddItems b: " << b << endl;
}

void run()
{
    Database db;
    AddItems(db);

    // db.Print();
    PrintDatabase(db);
}

} // namespace Ref

namespace Ref2
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
    string Str() const
    {
        return "Item: " + mName;
    }

    string mName;
};

class Database
{
  public:
    void AddItem(const Item &item)
    {
        cout << "addressof " << item.mName << ": " << addressof(item) << endl;
        mItemRefs.push_back(item);

        mMap[addressof(item)] = ++mCounter;
    }
    void Print() const
    {
        for (auto &itemRef : mItemRefs)
            itemRef.get().Print();
    }
    int Get(const shared_ptr<Item> &ptr) const
    {
        const Item *p = ptr.get();
        auto v = mMap.at(p);
        return v;
    }

    int mCounter = 0;
    vector<reference_wrapper<const Item>> mItemRefs;
    unordered_map<const Item *, int> mMap;
};

void AddItems(Database &db)
{
    auto itemSp1 = make_shared<Item>("aa");
    auto itemSp2 = make_shared<Item>("bb");

    cout << "itemSp1: " << itemSp1 << endl;
    cout << "itemSp2: " << itemSp2 << endl;

    db.AddItem(*itemSp1);
    db.AddItem(*itemSp2);
}

void run()
{
    Database db;

    auto itemSp1 = make_shared<Item>("aa");
    auto itemSp2 = make_shared<Item>("bb");
    db.AddItem(*itemSp1);
    db.AddItem(*itemSp2);
    // AddItems(db);

    db.Print();

    cout << db.Get(itemSp1) << endl;
    cout << db.Get(itemSp2) << endl;
}

} // namespace Ref2

namespace Inferitance
{

class Book
{
  public:
    Book(const string &title) : mTitle(title)
    {
    }
    void Print()
    {
        cout << Prefix() << ":" << mTitle << endl;
    }
    virtual string Prefix() = 0;

    string mTitle;
};

class Novel : public Book
{
  public:
    Novel(const string &title) : Book(title)
    {
    }
    string Prefix() override
    {
        return "Novel ";
    }
};

class BookDatabase
{
  public:
    void Add(const shared_ptr<Book> &book)
    {
        mBooks.push_back(book);
    }
    vector<shared_ptr<Book>> mBooks;
};

void AddBook(BookDatabase &db, const shared_ptr<Novel> &n1)
{
    db.Add(n1);
}

void run()
{
    BookDatabase db;

    auto n1 = make_shared<Novel>("novel1");
    AddBook(db, n1);
}

} // namespace Inferitance

namespace UniquePtr
{

class Obj
{
  public:
    Obj(const string &name) : name(name)
    {
    }
    Obj(const Obj &other) : name(other.name)
    {
        if (&other == this)
            cout << "from the same!" << endl;
        else
            cout << "from some other!" << endl;
    }

    Obj &operator=(const Obj &other)
    {
        if (&other == this)
        {
            cout << "from the same!" << endl;
            // nothing to do
        }
        else
        {
            cout << "from some other!" << endl;
            name = other.name;
        }
        return *this;
    }

    void PrintAddress()
    {
        cout << this << endl;
    }

    void Print()
    {
        cout << name << endl;
    }

    string name;
};

class Bucket
{
  public:
    Bucket(unique_ptr<Obj> &&obj) : obj(move(obj))
    {
    }
    void PrintObj()
    {
        obj->Print();
    }

    Obj &getObj()
    {
        return *obj;
    }

  private:
    unique_ptr<Obj> obj;
};

void run()
{
    auto o1 = make_unique<Obj>("aaa");

    Bucket b(move(o1));
    b.getObj().name = "bbb";

    b.PrintObj();
}

} // namespace UniquePtr

} // namespace smart_pointer

int main(int argc, char const *argv[])
{
    // smart_pointer::NestedPtr::run();
    // smart_pointer::Nullptr::run();
    smart_pointer::UniquePtr::run();
    // smart_pointer::Const::run2();
    // smart_pointer::Ref::run();
    // smart_pointer::Ref2::run();
    // smart_pointer::Inferitance::run();
    return 0;
}
