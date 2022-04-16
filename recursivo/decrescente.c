#include <stdio.h>

void decrescente(int n)
{
    printf("%d\n", n);
    if (n == 1)
    {
        printf("%d\n", 1);
        return;
    }
    decrescente(n - 1);
}

int main()
{
    decrescente(10);
}