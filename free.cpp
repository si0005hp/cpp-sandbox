#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "all.h"

using namespace std;

namespace Free
{

typedef struct
{
    int id;
    char *name;
} Item;

typedef struct
{
    int status;
    Item *item;
} Bucket;

void printItem(Item *item)
{
    printf("%s: %d\n", item->name, item->id);
}

Bucket *makeBucket(int id, char *name)
{
    Item *item = new Item();
    item->id = id;
    item->name = name;

    Bucket *bucket = new Bucket();
    bucket->status = 0;
    bucket->item = item;

    return bucket;
}

void freeBucket(Bucket *b)
{
    delete b->item;
    delete b;
}

void run()
{
    unsigned long counter = 0;
    while (1)
    {
        Bucket *b = makeBucket(
            0, (char *)"veryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryvery"
                       "veryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryvery"
                       "veryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryvery"
                       "veryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryvery"
                       "veryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryvery"
                       "veryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryveryvery long string");
        freeBucket(b);

        counter++;
        if (counter % 10000 == 0)
            sleep(1);
    }
}

} // namespace Free

int main(int argc, char const *argv[])
{
    Free::run();
    return 0;
}
