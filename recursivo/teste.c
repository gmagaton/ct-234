#include <stdio.h>
int c = 0;

int exec(int n)
{
    if (n <= 0)
        return 1;

    c++;
    return exec(n - 1) + exec(n - 1) + exec(n - 1);
}

int main()
{
    int x = exec(5);
    printf("X: %d\n", x);
    printf("C: %d\n", c);
}