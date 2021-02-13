#include "all.h"

using namespace std;

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

int main(int argc, char const *argv[])
{
    NestedPtr::run();
    return 0;
}
