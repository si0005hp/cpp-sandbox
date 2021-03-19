#include "all.h"

using namespace std;

namespace Interface
{

class IPrinter
{
  public:
    virtual void print(const string &msg) const = 0;
};

class AstarPrinter : public IPrinter
{
  public:
    virtual void print(const string &msg) const
    {
        cout << "*********************************" << endl;
        cout << msg << endl;
        cout << "*********************************" << endl;
    }
};

class LinePrinter : public IPrinter
{
  public:
    virtual void print(const string &msg) const
    {
        cout << "---------------------------------" << endl;
        cout << msg << endl;
        cout << "---------------------------------" << endl;
    }
};

class PrinterUser
{
  public:
    PrinterUser(IPrinter &printer) : printer_(printer) {}

    void print(const string &msg) const { printer_.print(msg); }

  private:
    IPrinter &printer_;
};

void run()
{
    IPrinter *astarP = new AstarPrinter();
    IPrinter *lineP = new LinePrinter();

    // PrinterUser u(*astarP);
    PrinterUser u(*lineP);
    u.print("sample message");
}

} // namespace Interface

int main(int argc, char const *argv[])
{
    Interface::run();
    return 0;
}
