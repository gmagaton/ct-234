#include <stdio.h>

int v[] = {10, 50, 43, 87, 33, 23, 12, 34, 76, 44, 56};

int presente(int x, int i, int f)
{
    if (i >= f)
    {
        return -1;
    }
    if (v[i] == x)
    {
        return i;
    }

    return presente(x, i + 1, f);
}

int main()
{
    int i = presente(76, 0, 10);

    printf("Valor na posição %d ", i);
}