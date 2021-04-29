#include "../all.h"
#include "CustomAllocator.h"
#include "Managed.h"

void *operator new(size_t size)
{
    std::cout << "ALLOC: " << size << " bytes" << std::endl;
    return malloc(size);
}

void operator delete(void *memory, size_t size)
{
    std::cout << "FREE: " << size << " bytes" << std::endl;
    free(memory);
}

namespace lib
{

// class TestObject : public Managed
class TestObject
{
  public:
    TestObject() : id_(0), name_("") {}
    TestObject(int id, const std::string &name) : id_(id), name_(name) {}

    ~TestObject() { std::cout << "TestObject destructed" << std::endl; }

    void print() { std::cout << "<TestObject> id: " << id_ << ", name: " << name_ << std::endl; }

    int id_;
    std::string name_;
};

struct TestEmptyObject
{
};
struct TestCharObject
{
    char c;
};
struct TestIntObject
{
    int i;
};
struct TestVObject
{
    virtual void hello() {}
};

} // namespace lib

using namespace lib;
using namespace std;

int main(int argc, char const *argv[])
{
    // TestObject *o = new TestObject();
    // o->id_ = 1;
    // o->name_ = "sample";
    // o->print();

    // std::vector<int, MyAllocator<int>> v;
    // v.reserve(10);
    // for (size_t i = 0; i < 10; i++) { v.push_back(i); }

    // std::cout << "---1---" << std::endl;
    // std::cout << "---2---" << std::endl;

    // std::vector<TestObject *, MyAllocator<TestObject *>> v;
    // v.emplace_back(1, "a");
    // v.emplace_back(1, "a");
    // v.emplace_back(1, "a");
    // v.emplace_back(1, "a");

    // TestObject o;
    // o.id_ = 1;
    // o.name_ = "aaa";
    // o.print();
    // Memory::freeObj(&o);
    // o.print();

    // ===== heap is allocated by Memory =====
    void *mem = Memory::allocate(sizeof(TestObject));
    TestObject *o = ::new (mem) TestObject();

    // ===== heap is allocated by Global new =====
    // TestObject *o = new TestObject();

    o->id_ = 1;
    o->name_ = "sample";
    o->print();

    cout << sizeof(uintptr_t) << endl;
    cout << sizeof(TestEmptyObject) << endl;
    cout << sizeof(TestCharObject) << endl;
    cout << sizeof(TestIntObject) << endl;
    cout << sizeof(TestVObject) << endl;

    return 0;
}
