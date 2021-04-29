#include "all.h"

namespace Container
{

using namespace std;

namespace Stack
{

typedef int MyInt;

void run()
{
    stack<MyInt> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty())
    {

        cout << s.top() << endl;
        s.pop();
    }

    stack<unordered_map<int, string>> s2;
    s2.push({{1, "one"}});
    s2.push({{2, "two"}});
    while (!s2.empty())
    {
        auto m = s2.top();
        cout << m.size() << endl;
        s2.pop();
    }
}

} // namespace Stack

namespace Vector
{

void a(int arg)
{
    cout << &arg << endl;
}

void b(int &arg)
{
    cout << &arg << endl;
}

void sa(string arg)
{
    cout << &arg << endl;
}

void sb(string &arg)
{
    cout << &arg << endl;
}

void va(vector<string> arg)
{
    cout << &arg << endl;
}

void vb(vector<string> &arg)
{
    cout << &arg << endl;
}

void run()
{

    // string s = "aaa";
    // cout << &s << endl;
    // // sa(s);
    // sb(s);

    // vector<int> v{1, 2, 3};
    // for (auto i : v)
    //     cout << &i << endl;

    // vector<string> v2{"a", "b", "c"};
    // for (auto i : v2) cout << &i << endl;
    // // va(v2);
    // vb(v2);

    vector<int> v;

    for (size_t i = 1; i <= 10; i++)
    {
        cout << "capacity: " << v.capacity() << "\n";
        v.push_back(i);
    }
    for (auto &&i : v) { cout << i << "\n"; }

    v.resize(3);
    cout << "-----\n";

    for (size_t i = 1; i <= 5; i++)
    {
        cout << "capacity: " << v.capacity() << "\n";
        v.push_back(i);
    }
    for (auto &&i : v) { cout << i << "\n"; }
}

} // namespace Vector

namespace Deque
{

void run()
{
    deque<int> d;
    d.push_front(1);
    d.push_front(2);

    for (auto i : d) cout << i << endl;

    cout << d.at(0) << endl;
    cout << d.front() << endl;

    while (!d.empty())
    {
        cout << d.front() << endl;
        d.pop_front();
    }
}

void run2()
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    for (auto i : d) cout << i << endl;

    cout << "-----" << endl;

    cout << d[2 - 1] << endl;
}

} // namespace Deque

namespace Size
{

struct Item
{
    int a;
    // int b;
    // int c;
    // int d;
    // int e;
    // int f;
    // int g;
    // int h;
    // int i;
    // int j;

    void print() { cout << a << endl; }
    void print() const { cout << "const" << a << endl; }
};

vector<Item> v;
// vector<Item *> v;

void GenVector(int count)
{
    for (size_t i = 0; i < count; i++) v.push_back(Item());
}

void addItem(int i)
{
    Item item;
    item.a = i;
    v.push_back(item);
}

void run()
{
    // while (true)
    // {
    //     GenVector(10000);
    //     sleep(1);
    // }

    addItem(1);
    addItem(2);
    addItem(3);

    for (auto item : v)
    {
        // item.print();
        item.a++;
    }

    for (auto &item : v) { item.print(); }
}

} // namespace Size

namespace CopyCotainer
{

struct Obj
{
    Obj(int id) : id(id) { cout << "Obj " << id << " constructed!" << endl; }

    Obj(const Obj &other) : id(other.id) { cout << "Obj " << id << " copied!" << endl; }

    int id;
};

void PrintAddress(const vector<Obj> &objs)
{
    for (auto &o : objs) { cout << &o << endl; }
}

void run()
{
    // Obj o1 = Obj(1);
    vector<Obj> v1;
    v1.reserve(3);
    v1.emplace_back(1);
    v1.emplace_back(2);
    v1.emplace_back(3);

    vector<Obj> v2(v1);
    // vector<Obj> v2(move(v1));
}

} // namespace CopyCotainer

} // namespace Container

int main(int argc, char const *argv[])
{
    // Container::Stack::run();
    Container::Vector::run();
    // Container::Deque::run();
    // Container::Deque::run2();
    // Container::Size::run();
    // Container::CopyCotainer::run();
    return 0;
}
