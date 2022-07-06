#include <stdio.h>

void crescente(int n)
{
    if (n == 1)
    {
        printf("%d ", 1);
        return;
    }
    crescente(n - 1);
    printf("%d ", n);
}

int main()
{
    crescente(10);
}