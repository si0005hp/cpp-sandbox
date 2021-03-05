#include "all.h"

using namespace std;

namespace Constructor
{
class Item
{
  public:
    Item() : Item(make_shared<string>("default")) {}

    Item(const shared_ptr<string>& name) : mName(name), mSubName(mName) {}

    void Print() { cout << "[Item] " << *mName << "-" << *mSubName << endl; }

    shared_ptr<string> mName;
    shared_ptr<string> mSubName;
};

void run()
{
    shared_ptr<string> s = make_shared<string>("foo");

    for (auto&& i : vector<int>())
        cout << i << endl;

    Item foo(s);
    Item def;

    foo.Print();
    def.Print();
}

void foo()
{
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         << endl;
}

} // namespace Constructor

using namespace Constructor;

int main(int argc, char const* argv[])
{
    if (1)
        cout << "[Item] " << endl;
    else
        cout << "[Item] " << endl;

    Constructor::run();
    return 0;
}
