#include "all.h"

using namespace std;

namespace Lambda
{

void inc()
{
    int i = 0;
    auto inc = [](auto value) { value++; };

    for (size_t i = 0; i < 5; i++)
        inc(i);
    cout << i << endl;
}

void inc2()
{
    int i = 0;
    auto inc2Copy = [=]() { return i + 1; };

    for (size_t i = 0; i < 5; i++)
        cout << inc2Copy() << endl;

    cout << "-----------" << endl;

    auto inc2Ref = [&]() {
        i++;
        return i;
    };

    for (size_t i = 0; i < 5; i++)
        cout << inc2Ref() << endl;

    cout << "final i: " << i << endl;
}

void WithIntConsumer(const function<void(int intParam1)> &intConsumer, int intArg1)
{
    intConsumer(intArg1);
}

void ftype()
{
    WithIntConsumer(
        [=](int intArg1) {
            intArg1++;
            cout << intArg1 << endl;
        },
        1);

    int base = 10;
    WithIntConsumer([=](int intArg1) { cout << base * intArg1 << endl; }, 9);
}

} // namespace Lambda

int main(int argc, char const *argv[])
{
    Lambda::ftype();
    return 0;
}
