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

    EnumerateAnyArray(v);
    return 0;
}
