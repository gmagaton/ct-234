#include <stdio.h>

int soma(int n)
{
    if (n == 0)
        return 0;
    return n + soma(n - 1);
}

int main()
{
    int r = soma(5);
    printf("Soma recursiva de 5 é : %d\n", r);
    return 0;
}