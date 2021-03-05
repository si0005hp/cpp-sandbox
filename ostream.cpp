#include "all.h"

using namespace std;

namespace Ostream
{

class Writer
{
  public:
    Writer(std::ostream &os) : mOs(os) {}
    void Write(const string &s) { mOs << s; }
    void Writeln(const string &s) { mOs << s << endl; }

    std::ostream &mOs;
};

void run()
{
    Writer w(std::cout);
    w.Write("aaa");
    w.Writeln("bbb");
    w.Writeln("12345");

    std::ostringstream oss;
    Writer w2(oss);
    w2.Write("ccc");
    w2.Writeln("ddd");
    w2.Writeln("999");

    cout << oss.str() << endl;
}

} // namespace Ostream

int main(int argc, char const *argv[])
{
    Ostream::run();
    return 0;
}
