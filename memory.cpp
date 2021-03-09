#include <iostream>
#include <string>

#include "all.h"

using namespace std;

static uint32_t allocCount = 0;

void *operator new(size_t size)
{
    allocCount++;
    std::cout << "Alloc: " << size << " bytes" << std::endl;
    return malloc(size);
}

// namespace Memory
// {

// } // namespace Memory

// using namespace Memory;

// using namespace std;

struct MyStruct
{
    MyStruct(int i) : i(i) {}
    int i;
};

void Print(const MyStruct &s)
{
    cout << s.i << endl;
}

void Print(const string &s)
{
    cout << s << endl;
}

int main(int argc, char const *argv[])
{
    // MyStruct *m = new MyStruct(1);
    //     Print(*m);

    string fullname = "John Thirteen";
    string firstName = fullname.substr(0, 4);
    string lastName = fullname.substr(5, 9);

    Print(fullname);
    Print(firstName);
    Print(lastName);

    return 0;
}
