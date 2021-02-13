#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    int price;
} Item;

Item makeItem(char *name, int price)
{
    Item i;
    i.name = "aaa";
    i.price = 100;
    return i;
}

Item makeItem2(char *name, int price)
{
    Item *i = malloc(sizeof(Item));
    i->name = name;
    i->price = price;
    return *i;
}

// NG
Item *makeItemPointer1(char *name, int price)
{
    Item i;
    i.name = name;
    i.price = price;
    return &i;
}

Item *makeItemPointer2(char *name, int price)
{
    Item *i = malloc(sizeof(Item));
    i->name = name;
    i->price = price;
    return i;
}

int main(int argc, char const *argv[])
{
    // Item i = makeItem("aaa", 100);
    // Item i = makeItem2("aaa", 100);

    // Item *ip = makeItemPointer1("aaa", 100);

    Item *ip = makeItemPointer2("aaa", 100);
    Item i = *ip;

    // print item
    printf("[Item] %s %d$\n", i.name, i.price);
    return 0;
}
