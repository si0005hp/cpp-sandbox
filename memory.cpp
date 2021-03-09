#include <iostream>
#include <memory_resource>
#include <string>

#include "all.h"

using namespace std;

static uint32_t allocCount = 0;
static uint32_t totalAllocSize = 0;

static uint32_t currentAllocSize = 0;

void *operator new(size_t size)
{
    allocCount++;
    totalAllocSize += size;
    currentAllocSize += size;

    std::cout << "ALLOC: " << size << " bytes" << std::endl;
    return malloc(size);
}

void operator delete(void *memory, size_t size)
{
    currentAllocSize -= size;

    std::cout << "FREE: " << size << " bytes" << std::endl;
    free(memory);
}

static void line(int i)
{
    std::cout << "--- " << i << " ---" << std::endl;
}

using namespace std;

struct MyStruct
{
    MyStruct(int a) : a(a)
    {
        cout << "MyStruct " << a << " is constructed!" << endl;
    }
    ~MyStruct() { cout << "MyStruct " << a << " is destructed!" << endl; }

    int a;
};

vector<MyStruct *> makeVector(size_t size)
{
    line(1);
    vector<MyStruct *> v;
    line(2);
    for (size_t i = 0; i < size; i++)
    {
        MyStruct *s = new MyStruct(i + 1);
        v.push_back(s);

        // v.emplace_back(i + 1);
    }
    line(3);
    return v;
}

vector<string> makeStringVector(size_t size)
{
    vector<string> v;
    for (size_t i = 0; i < size; i++)
    {
        v.push_back(
          "shdgkjhfhgrvjgvzsjfvkrytvfjhztrvfjzrytvfjztrfvjzyrtfkzrfdsgdfsgsfgsf"
          "dgsfgsfgsfdgsfdgsfgsfgsgfdgergvkrtfvkzsrtvfkzstrfvkzsrtfvzktsvr" +
          to_string(i));
    }
    return v;
}

vector<unique_ptr<string>> makeStringPtrVector(size_t size)
{
    vector<unique_ptr<string>> v;
    for (size_t i = 0; i < size; i++)
    {
        unique_ptr<string> p = make_unique<string>(to_string(i));
        v.push_back(move(p));
    }
    return v;
}

MyStruct createMyStruct(int n)
{
    MyStruct m(n);
    return m;
}

int main(int argc, char const *argv[])
{
    int cnt = atoi(argv[1]);

    // line(0);
    // auto v = makeVector(cnt);
    // line(4);

    // vector<string> v;
    // for (size_t i = 0; i < cnt; i++) { v.push_back(to_string(i)); }

    // while (true)
    // {
    //     makeStringVector(1000);
    //     sleep(1);
    // }

    // string s = "fsdfhgsfjhskfjdhsjkdskjd";
    // unique_ptr<string> p(s);

    // unique_ptr<string> p = make_unique<string>("fsdfhgsfjhskfjdhsjkdskjd");
    // vector<unique_ptr<string>> v;
    // v.push_back(move(p));

    // vector<unique_ptr<string>> v = makeStringPtrVector(5);
    // for (auto &p : v) cout << *p << endl;

    line(1);
    MyStruct s = createMyStruct(1);
    line(2);

    cout << "[totalAllocSize]: " << totalAllocSize << endl;
    cout << "[currentAllocSize]: " << currentAllocSize << endl;

    return 0;
}
