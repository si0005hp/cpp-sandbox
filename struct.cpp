#include "all.h"

using namespace std;

namespace Struct
{

typedef uint64_t Value;

struct Foo
{
    Foo() {}
    Foo(const string &msg) : mMsg(msg) {}
    const string mMsg;
};

typedef struct
{
    Value stack[100];
    Value *stackTop;
} Stack;

struct Obj
{
    bool isMarked;
    struct Obj *next;
};

typedef struct Obj Obj;

void run()
{
    cout << sizeof(Stack) << endl;
    cout << sizeof(Obj) << endl;
}

} // namespace Struct

int main(int argc, char const *argv[])
{
    Struct::run();
    return 0;
}
