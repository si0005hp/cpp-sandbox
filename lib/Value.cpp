#include "Value.h"

namespace lib
{

Value::Value(double number)
{
    memcpy(&value_, &number, sizeof(Value));
}

double Value::AsNumber() const
{
    double number;
    memcpy(&number, &value_, sizeof(double));
    return number;
}

} // namespace lib

using namespace lib;
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Sizeof Value: " << sizeof(Value) << endl;

    /* Number */
    Value v(12.4);
    cout << v.AsNumber() << endl;

    return 0;
}
