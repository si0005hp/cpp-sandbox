#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}
