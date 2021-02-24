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

    vector<string> v2{"a", "b", "c"};
    for (auto i : v2)
        cout << &i << endl;
    // va(v2);
    vb(v2);
}

} // namespace Vector

namespace Deque
{

void run()
{
    deque<int> d;
    d.push_front(1);
    d.push_front(2);

    for (auto i : d)
        cout << i << endl;

    cout << d.at(0) << endl;
    cout << d.front() << endl;

    while (!d.empty())
    {
        cout << d.front() << endl;
        d.pop_front();
    }
}

} // namespace Deque

} // namespace Container

int main(int argc, char const *argv[])
{
    // Container::Stack::run();
    // Container::Vector::run();
    Container::Deque::run();
    return 0;
}
