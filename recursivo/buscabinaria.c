#include <stdio.h>

int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int buscaBinaria(int n, int x, int l, int r)
{
    int m = (l + r) / 2;

    if (v[m] == x)
    {
        return m ;
    }

    if (l >= r)
    {
        return -1;
    }

    if (v[m] < x)
    {
        l = m + 1;
        return buscaBinaria(n, x, m + 1, r);
    }
    else
    {
        return buscaBinaria(n, x, l, m - 1);
    }
}

int main()
{
    int x = 8;
    int p = buscaBinaria(10, x, 0, 9);
    printf("Valor %d está na posição %d", x, p);
    return 0;
}