#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
} Obj;

int main(int argc, char const *argv[])
{
    // char *foo = "abc";

    // printf("%s\n", foo);

    // printf("%p: %c\n", foo, *foo);
    // foo++;
    // printf("%p: %c\n", foo, *foo);
    // foo++;
    // printf("%p: %c\n", foo, *foo);

    // printf("%p: %c\n", foo, foo[0]);
    // printf("%p: %c\n", foo, foo[1]);
    // printf("%p: %c\n", foo, foo[2]);

    int *nums = malloc(sizeof(int) * 3);
    int *start = nums;
    for (int i = 0; i < 3; i++)
    {
        *nums = (i + 1) * (i + 2);
        nums++;
    }

    printf("%p\n", start);

    for (int i = 0; i < 3; i++)
    {
        // printf("%p: %d\n", start, *start);
        // start++;
        printf("%p: %d\n", start, start[i]);
    }

    printf("-----\n");

    Obj *objs = malloc(sizeof(Obj) * 3);
    Obj *start2 = objs;
    for (int i = 0; i < 3; i++)
    {
        printf("objs: %p\n", objs);
        // objs->num = i;
        // objs++;
        objs[i].num = i;
    }

    for (int i = 0; i < 3; i++)
    {
        // Obj o = start2[i];
        // printf("%d\n", o.num);

        printf("start2: %p\n", start2);
        // printf("%d\n", start2->num);
        // start2++;
        Obj o = start2[i];
        printf("%d\n", o.num);
    }

    return 0;
}
