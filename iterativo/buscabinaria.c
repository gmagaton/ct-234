#include <stdio.h>

int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int buscaBinaria(int n, int x)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {

        int m = (l + r) / 2;

        if (v[m] == x)
        {
            return m - 1;
        }

        if (v[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    int x = 6;
    int p = buscaBinaria(10, x);
    printf("Valor %d está na posição %d", x, p);
    return 0;
}