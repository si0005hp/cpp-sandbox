#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

inline bool isDebugEnabled()
{
    static char *env;
    if (!env) env = std::getenv("DEBUG");

    return env ? std::strcmp(env, "1") == 0 : false;
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 3; i++)
    {
        if (isDebugEnabled())
            std::cout << "enabled" << std::endl;
        else
            std::cout << "not enabled" << std::endl;
    }
    return 0;
}
