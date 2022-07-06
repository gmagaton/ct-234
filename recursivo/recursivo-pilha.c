#include <stdio.h>

int rec(int n)
{
    if (n <= 0)
    {
        return 1;
    }

    return rec(n - 1) + rec(n - 1) + rec(n - 1) + rec(n - 1);
}

int main()
{
    int n = 12;
    int x = rec(n);
    printf("N = %d X = %d\n", n, x);
    return 0;
}