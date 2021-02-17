#include "all.h"

using namespace std;

namespace Map
{

namespace UnorderedMap
{

void PrintMap(const unordered_map<int, string> &map)
{
    for (auto &[k, v] : map)
    {
        cout << k << ":" << v << endl;
    }
}

void run()
{
    unordered_map<int, string> map;
    map.emplace(1, "one");
    map.emplace(2, "two");
    // map.emplace(2, "two-later");
    map[2] = "two-later";

    PrintMap(map);
}

void run2()
{
    unordered_map<int, shared_ptr<string>> map;
    map.emplace(1, make_shared<string>("one"));
    map.emplace(2, nullptr);

    if (map.contains(1))
        cout << "contains 1" << endl;
    if (map.contains(2))
        cout << "contains 2" << endl;
    if (map.contains(3))
        cout << "contains 3" << endl;
}

} // namespace UnorderedMap

} // namespace Map

int main(int argc, char const *argv[])
{
    Map::UnorderedMap::run2();
    return 0;
}
