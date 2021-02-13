#include "all.h"

using namespace std;

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

template <typename Base, typename T> inline bool instanceof (const T &)
{
    return is_base_of<Base, T>::value;
}

template <typename T> void doCheck(const T &t)
{
    if (instanceof <Number>(t))
    {
        cout << "is instance of Number class" << endl;
    }
    if (instanceof <Expr>(t))
    {
        cout << "is instance of Expr class" << endl;
    }
    if (instanceof <string>(t))
    {
        cout << "is instance of string class" << endl;
    }
}

int main(int argc, char const *argv[])
{

    shared_ptr<Number> np = make_shared<Number>(1);
    const string &s = "foo";

    doCheck(*np);
    doCheck(s);

    return 0;
}
