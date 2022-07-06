#include <stdio.h>

int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int n = 10;

int buscaBinaria(int n, int x, int i, int f)
{
    if (n == 0)
    {
        return -1;
    }
    int m = (i + f) / 2;
    if (v[m] == x)
    {
        return m;
    }
    if (v[m] > x)
    {
        return buscaBinaria(n / 2, x, i, m);
    }
    else
    {
        return buscaBinaria(n / 2, x, m, f);
    }
}

int main()
{
    int x = 8;
    int p = buscaBinaria(n - 1, x, 0, n - 1);
    printf("Valor %d está na posição %d", x, p);
    return 0;
}