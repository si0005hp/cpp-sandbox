#include "all.h"

using namespace std;

template <typename T> bool IsType(any a)
{
    try
    {
        any_cast<T>(a);
        return true;
    }
    catch (bad_any_cast &e)
    {
        return false;
    }
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

int main(int argc, char const *argv[])
{
    vector<any> v;
    v.push_back(make_shared<int>(1));
    v.push_back(1);
    v.push_back("aaa");
    v.push_back(string("aaa"));

    v.push_back(vector<int>{1, 2, 3});
    v.push_back(vector<string>{"a", "b", "c"});
    EnumerateAnyArray(v);

    // vector<string> vs{"a", "b", "c"};
    // ConvertToAnyVector(vs);
    return 0;
}
