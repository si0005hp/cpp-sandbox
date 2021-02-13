#include "all.h"

using namespace std;

class MyException : public exception
{
  public:
    MyException(const string &msg) : m_msg(msg)
    {
        cout << "MyException::MyException - set m_msg to:" << m_msg << endl;
    }

    ~MyException()
    {
        cout << "MyException::~MyException" << endl;
    }

    virtual const char *what() const throw()
    {
        cout << "MyException - what" << endl;
        return m_msg.c_str();
    }

    const string m_msg;
};

void doSome(const string &msg)
{
    throw(MyException(msg));
}

int main(int argc, char const *argv[])
{
    try
    {
        doSome("some error");
    }
    catch (int e)
    {
        cout << "came here1" << endl;
    }
    catch (string e)
    {
        cout << "came here2" << endl;
    }
    catch (const MyException &e)
    {
        cout << "came here3" << endl;
        cout << e.what() << endl;
    }
    return 0;
}
