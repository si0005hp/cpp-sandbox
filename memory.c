#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char *name;
} Item;

Item *makeItem(int id, char *name)
{
    Item *item = realloc(NULL, sizeof(Item));
    item->id = id;
    item->name = name;
    return item;
}

void printItem(Item *item)
{
    printf("[Item] id: %d, name: %s\n", item->id, item->name);
}

int main(int argc, char const *argv[])
{
    Item *item = makeItem(1, "aaa");

    printItem(item);

    return 0;
}
