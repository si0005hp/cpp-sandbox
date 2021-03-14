#include "all.h"

using namespace std;

namespace Size
{

class Item;

class Obj
{
  public:
    void doSomething(Item item);

  private:
    Item *i;
};

void run()
{
    cout << sizeof(Obj) << endl;
}

} // namespace Size

int main(int argc, char const *argv[])
{
    Size::run();
    return 0;
}
