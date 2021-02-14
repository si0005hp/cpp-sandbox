#include "all.h"

using namespace std;

namespace Optional
{

using namespace std;

template <typename T> void Inspect(const optional<T> &opt)
{
    if (opt.has_value())
    {
        cout << "Has value: " << opt.value() << endl;
    }
    else
    {
        cout << "Not have value" << endl;
    }
}

void run()
{
    int defaultVal = 187;

    optional<int> optNum = make_optional<int>(99);
    Inspect(optNum);
    cout << optNum.value_or(defaultVal) << endl;

    optional<int> nullOpt = nullopt;
    Inspect(nullOpt);
    cout << nullOpt.value_or(defaultVal) << endl;
}

} // namespace Optional

int main(int argc, char const *argv[])
{
    Optional::run();
    return 0;
}
