#include "all.h"

using namespace std;

namespace Reference
{

class Message
{
  public:
    Message(const string &msg) : mMsg(msg)
    {
    }
    string mMsg;
};

void SendMessage(const Message &msg)
{
    cout << "*** " << msg.mMsg << " ***" << endl;
}

void run()
{
    Message m("hi there");
    SendMessage(m);
}

} // namespace Reference

int main(int argc, char const *argv[])
{
    Reference::run();
    return 0;
}
