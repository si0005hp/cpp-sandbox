#include "all.h"

using namespace std;

namespace Instanceof
{

class Expr
{
  public:
    virtual void Show() const = 0;
};

class BinOp : public Expr
{
  public:
    BinOp(const Expr &mLeft, const Expr &mRight, const char mOp) : mLeft(mLeft), mRight(mRight), mOp(mOp)
    {
    }
    void Show() const
    {
        mRight.Show();
        mLeft.Show();
    }

  private:
    const Expr &mLeft;
    const Expr &mRight;
    const char mOp;
};

class Number : public Expr
{
  public:
    Number(int val) : val(val)
    {
    }
    void Show() const
    {
        cout << val << endl;
    }

    int val;
};

// template <typename Base, typename T> inline bool instanceof (const T *)
// {
//     return is_base_of<Base, T>::value;
// }

template <typename Base, typename T> inline bool Instanceof(const T &)
{
    return is_base_of<Base, T>::value;
}

template <typename T> void DoCheck(T &t)
{
    if (Instanceof<string>(t))
    {
        cout << "is instance of string class" << endl;
    }
    else if (Instanceof<Number>(t))
    {
        cout << "is instance of Number class" << endl;
    }
    else if (Instanceof<Expr>(t))
    {
        cout << "is instance of Expr class" << endl;
    }
}

void run()
{
    // shared_ptr<Number> np = make_shared<Number>(1);
    // const string &sref = "foo";
    // const string s = "foo";

    // DoCheck(*np);
    // DoCheck(sref);
    // DoCheck(s);

    shared_ptr<Expr> expr = make_shared<Number>(999);

    // if (typeid(np) == typeid(shared_ptr<Number>))
    // {
    //     cout << "true" << endl;
    // }
    if (typeid(*expr) == typeid(Number))
    {
        cout << "true" << endl;
        auto n = static_pointer_cast<Number>(expr);
        cout << n->val << endl;
    }
}

} // namespace Instanceof

int main(int argc, char const *argv[])
{
    Instanceof::run();
    return 0;
}
