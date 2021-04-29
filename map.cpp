#include "all.h"

using namespace std;

namespace Map
{

namespace UnorderedMap
{

struct Item
{
    Item(const string &name) : name(name) { cout << "Item " << name << " constructed" << endl; }
    Item(const Item &other) : name(other.name) { cout << "Item " << name << " copied" << endl; }
    string name;
};

void PrintMap(const unordered_map<int, string> &map)
{
    for (auto &[k, v] : map) { cout << k << ":" << v << endl; }
}

void run()
{
    unordered_map<int, string> map;
    map.emplace(1, "one");
    map.emplace(2, "two");
    // map.emplace(2, "two-later");
    // map[2] = "two-later";

    // map.insert(std::make_pair(3, "three"));
    // map.insert(std::make_pair(3, "three2"));
    map.insert_or_assign(3, "three");
    map.insert_or_assign(3, "three2");

    PrintMap(map);
}

void run2()
{
    unordered_map<int, Item> map;

    // Item i1("one");
    // Item i2("two");
    // map.insert_or_assign(1, i1);
    // map.insert_or_assign(2, i2);

    // map.insert_or_assign(1, Item("one"));
    // map.insert_or_assign(2, Item("two"));

    map.emplace(1, "one");
    map.emplace(2, "two");
}

} // namespace UnorderedMap

} // namespace Map

int main(int argc, char const *argv[])
{
    Map::UnorderedMap::run2();
    return 0;
}
