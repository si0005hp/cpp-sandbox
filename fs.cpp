#include "all.h"

namespace Fs
{

using namespace std;

void run(string fileName)
{
    ifstream file;
    file.open(fileName, ios::in);
    if (file.fail())
        cout << "Failed to open file" << endl;

    stringstream ss;
    string line;
    while (getline(file, line))
    {
        if (line.find("\n") == string::npos)
            cout << "[line] not contains" << endl;
        else
            cout << "[line] contains" << endl;

        ss << line << endl;
    }

    if (ss.str().find("\n") == string::npos)
        cout << "not contains" << endl;
    else
        cout << "contains" << endl;
}

} // namespace Fs

int main(int argc, char const *argv[])
{
    Fs::run("Makefile");
    return 0;
}
