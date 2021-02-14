#include "all.h"

using namespace std;

namespace Virtual
{

using namespace std;

class BasePrinter
{
  public:
    void Print(const string &msg)
    {
        PrintLine();
        cout << msg << endl;
        PrintLine();
    }

    virtual void FinalPrint(const string &msg) final
    {
        PrintLine();
        cout << msg << endl;
        PrintLine();
    }

  protected:
    virtual void PrintLine()
    {
        throw "Not supposed to be called.";
    }
};

class Printer1 : public BasePrinter
{
  protected:
    void PrintLine() override
    {
        cout << "*******************************" << endl;
    }
};

class Printer2 : public BasePrinter
{
  protected:
    void PrintLine() override
    {
        cout << "================================" << endl;
    }
};

void run()
{
    // BasePrinter p1 = Printer1();
    // BasePrinter p2 = Printer2();

    BasePrinter *p1 = new Printer1();
    BasePrinter *p2 = new Printer2();

    p1->Print("msg by Printer1");
    p2->Print("msg by Printer2");

    p1->FinalPrint("FinalPrint by Printer1");
    p2->FinalPrint("FinalPrint by Printer2");
}

} // namespace Virtual

int main(int argc, char const *argv[])
{
    Virtual::run();
    return 0;
}
