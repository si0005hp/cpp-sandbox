#include "all.h"

using namespace std;

namespace Template
{

using namespace std;

class Value
{
  public:
    template <typename T>
    T As();
};

class String : public Value
{
  public:
    String(const string &value) : mValue(value) {}

    template <typename T>
    T As()
    {
        return mValue;
    }

    string mValue;
};

class Number : public Value
{
  public:
    Number(const double &value) : mValue(value) {}

    template <typename T>
    T As()
    {
        return mValue;
    }

    double mValue;
};

template <typename T>
T DynamicCast(Value &value)
{
    T &v = dynamic_cast<T &>(value);
    return v;
}

void run()
{
    // String s("a");
    // Value *v = new String("a");
    // v->As<string>();
    // String &s2 = dynamic_cast<String &>(v);

    // Value v2 = Number(12);

    // String s = DynamicCast<String>(v1);
    // DynamicCast(v2);
}

namespace Generic
{

class IPrintable
{
  public:
    virtual ~IPrintable() {}
    virtual void print() const = 0;
};

template <class T>
class Array
{
  public:
    ~Array()
    {
        for (auto &&p : v_)
            delete p;
    }

    void append(T *item) { v_.push_back(item); }
    void printAll() const
    {
        for (auto &&p : v_)
            p->print();
    }

  private:
    vector<IPrintable *> v_;
};

class Item : public IPrintable
{
  public:
    Item(const string &name) : name_(name) {}
    ~Item() { cout << "Destructor of " << name_ << " is called." << endl; }

    void print() const override { cout << name_ << endl; }

    string name_;
};

class ItemArray : public Array<Item>
{
};

void run()
{
    // Array<Item> items;
    ItemArray items;

    items.append(new Item("aaa"));
    items.append(new Item("bbb"));
    items.printAll();
}

} // namespace Generic

} // namespace Template

int main(int argc, char const *argv[])
{
    Template::Generic::run();
    return 0;
}
