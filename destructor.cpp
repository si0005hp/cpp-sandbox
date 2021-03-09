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

namespace Destructor
{

struct MyStruct
{
    MyStruct(int a) : a(a)
    {
        cout << "MyStruct " << a << " is constructed!" << endl;
    }
    ~MyStruct() { cout << "MyStruct " << a << " is destructed!" << endl; }

    int a;
};

struct Obj
{
    Obj(MyStruct &&m) : m_(move(m))
    {
        cout << "Obj with MyStruct " << m_.a << " is constructed!" << endl;
    }
    ~Obj()
    {
        cout << "Obj with MyStruct " << m_.a << " is destructed!" << endl;
    }

    MyStruct m_;
};

void run()
{
    line(1);
    // MyStruct m(1);
    line(2);
    Obj o(MyStruct(1));
    line(3);
}

} // namespace Destructor

int main(int argc, char const *argv[])
{

    Destructor::run();

    cout << "[totalAllocSize]: " << totalAllocSize << endl;
    cout << "[currentAllocSize]: " << currentAllocSize << endl;

    return 0;
}
