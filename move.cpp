#include "all.h"

using namespace std;

namespace Move
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

    string mName;
};

class Database
{
  public:
    Database(vector<Item> &&items) : mItems(std::move(items))
    {
    }
    void Print()
    {
        for (auto &&item : mItems)
            item.Print();
    }

    vector<Item> mItems;
};

void run()
{
    vector<Item> items{Item("a"), Item("b"), Item("c")};

    Database db(std::move(items));

    db.Print();

    cout << "-----" << endl;

    for (auto &&item : items)
        item.Print();
}

class Database2
{
  public:
    Database2(vector<shared_ptr<Item>> &&items) : mItems(std::move(items))
    {
    }
    void Print()
    {
        for (auto &&item : mItems)
        {
            cout << item << " ";
            item->Print();
        }
    }

    vector<shared_ptr<Item>> mItems;
};

void run2()
{
    vector<shared_ptr<Item>> items{make_shared<Item>("a"), make_shared<Item>("b"), make_shared<Item>("c")};
    for (auto &&item : items)
        cout << item << endl;
    cout << "-----" << endl;

    Database2 db(std::move(items));

    db.Print();

    cout << "-----" << endl;

    for (auto &&item : items)
        item->Print();
}

} // namespace Move

int main(int argc, char const *argv[])
{
    Move::run2();
    return 0;
}
