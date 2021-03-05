#include "all.h"

using namespace std;

namespace String
{

class Foo
{
  public:
    Foo(const string &msg) : mMsg(msg) {}
    const string mMsg;
};

void run()
{
    string s1 = "abc";
    cout << s1 + " def" << endl;

    Foo("a");
    Foo(s1 + "a");
    // Foo("a" + "a"); NG
    Foo(string("a") + "a");
    Foo("a" + string("a"));
}

} // namespace String

int main(int argc, char const *argv[])
{
    String::run();
    return 0;
}
