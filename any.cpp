#include "all.h"

using namespace std;

namespace AnyVector
{

template <typename T> bool IsType(any a)
{
    // try
    // {
    //     any_cast<T>(a);
    //     return true;
    // }
    // catch (bad_any_cast &e)
    // {
    //     return false;
    // }
    return IsType2<T>(a);
}

template <typename T> bool IsType2(any a)
{
    return a.type().name() == typeid(T).name();
}

template <typename T> vector<any> ConvertToAnyVector(const vector<T> &src)
{
    vector<any> dst;
    for (auto e : src)
    {
        dst.push_back(e);
    }
    return dst;
}

void EnumerateAnyArray(const vector<any> &arr)
{
    for (auto a : arr)
    {
        if (IsType<string>(a))
        {
            cout << "string type" << endl;
        }
        else if (IsType<char *>(a))
        {
            cout << "shared_ptr<int> type" << endl;
        }
        else if (IsType<int>(a))
        {
            cout << "int type" << endl;
        }
        else if (IsType<shared_ptr<int>>(a))
        {
            cout << "shared_ptr<int> type" << endl;
        }
        else if (IsType<vector<int>>(a))
        {
            cout << "vector<int> type" << endl;
            cout << "--- recursion start ---" << endl;
            EnumerateAnyArray(ConvertToAnyVector(any_cast<vector<int>>(a)));
            cout << "--- recursion end ---" << endl;
        }
        else if (IsType<vector<string>>(a))
        {
            cout << "vector<string> type" << endl;
            cout << "--- recursion start ---" << endl;
            EnumerateAnyArray(ConvertToAnyVector(any_cast<vector<string>>(a)));
            cout << "--- recursion end ---" << endl;
        }
        else
        {
            cout << "others" << endl;
        }
    }
}

string btos(bool b)
{
    return b ? "true" : "false";
}

void run()
{
    vector<any> v;
    v.push_back(make_shared<int>(1));
    v.push_back(1);
    v.push_back("aaa");
    v.push_back(string("aaa"));

    v.push_back(vector<int>{1, 2, 3});
    v.push_back(vector<string>{"a", "b", "c"});
    EnumerateAnyArray(v);
}

} // namespace AnyVector

void IsEqual(any x, any y)
{
    if (x.type().name() == y.type().name())
    {
        cout << "EQ" << endl;
    }
    else
    {
        cout << "NOT EQ" << endl;
    }
}

template <typename T> void Inspect(const any &a)
{
    p("--------------------------------------------");
    cout << "[a.type().name()]: " << a.type().name() << endl;
    cout << "[typeid(T).name()]: " << typeid(T).name() << endl;

    if (a.type().name() == typeid(T).name())
        p("EQ") else p("NOT EQ");
}

int main(int argc, char const *argv[])
{
    any x = 1;
    Inspect<int>(x);

    any y = "aaa";
    Inspect<char *>(y); // NOT EQ

    any z = string("aaa");
    Inspect<string>(z); // EQ

    any a = make_any<string>("aaa");
    Inspect<string>(a); // EQ

    auto ip = make_shared<int>(1);
    any ipa = make_any<shared_ptr<int>>(ip);
    ip = any_cast<shared_ptr<int>>(ipa);
    p(*ip);

    // AnyVector::run();

    return 0;
}
