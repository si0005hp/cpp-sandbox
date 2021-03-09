#include "all.h"

using namespace std;

namespace Array
{

// static uint32_t allocCount = 0;

// void *operator new(size_t size)
// {
//     allocCount++;
//     std::cout << "Alloc: " << size << " bytes" << std::endl;
//     return malloc(size);
// }

struct Task
{
};

struct Obj
{
    Obj() { t = new Task(); }

    ~Obj()
    {
        cout << "Obj destructor" << endl;
        if (t) { delete t; }
    }

    Task *t;
};

void allocateArrayOnHeap(const size_t size)
{
    Obj *arr = new Obj[size];
    for (size_t i = 0; i < size; i++)
    {
        Obj *o = new Obj();
        arr[i] = *o;
        // arr[i] = Obj();
    }

    // delete arr;
    delete[] arr;
}

void allocateArrayOnStack(const size_t size)
{
    Obj arr[100000];
    // for (size_t i = 0; i < size; i++) { arr[i] = Obj(); }
    for (size_t i = 0; i < size; i++) { arr[i] = *new Obj(); }
    // delete arr;
}

void run()
{
    // while (true)
    // {
    //     // allocateArrayOnStack(100000);
    //     allocateArrayOnHeap(100000);
    //     sleep(1);
    //     cout << "running..." << endl;
    // }

    // Obj *o = new Obj(1);
    // delete o;

    // Obj o = Obj(1);

    // Task *t = new Task();
    // delete t;
    // delete t;

    // Obj o[3];

    Obj *arr = new Obj[3];
    delete[] arr;
}

} // namespace Array

int main(int argc, char const *argv[])
{

    Array::run();

    return 0;
}
