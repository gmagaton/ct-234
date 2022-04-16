#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // This program will create same sequence of
    // random numbers on every program run

    for (int i = 1; i <= 10000000; i++)
        printf("%d,", rand());

    return 0;
}