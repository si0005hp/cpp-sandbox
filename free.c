#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    Item *item = malloc(sizeof(Item));
    item->id = id;
    item->name = name;

    Bucket *bucket = malloc(sizeof(Bucket));
    bucket->status = 0;
    bucket->item = item;

    return bucket;
}

void freeBucket(Bucket *b)
{
    free(b->item);
    free(b);
}

int main(int argc, char const *argv[])
{
    unsigned long counter = 0;
    while (1)
    {
        Bucket *b = makeBucket(0,
                               "veryveryveryveryveryveryveryveryveryveryveryver"
                               "yveryveryveryveryveryveryveryveryveryveryvery"
                               "veryveryveryveryveryveryveryveryveryveryveryver"
                               "yveryveryveryveryveryveryveryveryveryveryvery"
                               "veryveryveryveryveryveryveryveryveryveryveryver"
                               "yveryveryveryveryveryveryveryveryveryveryvery"
                               "veryveryveryveryveryveryveryveryveryveryveryver"
                               "yveryveryveryveryveryveryveryveryveryveryvery"
                               "veryveryveryveryveryveryveryveryveryveryveryver"
                               "yveryveryveryveryveryveryveryveryveryveryvery"
                               "veryveryveryveryveryveryveryveryveryveryveryver"
                               "yveryveryveryveryveryveryvery long string");
        freeBucket(b);

        counter++;
        if (counter % 10000 == 0)
            sleep(1);
    }
    return 0;
}
