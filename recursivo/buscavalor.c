#include <stdio.h>

int v[] = {10, 50, 43, 87, 33, 23, 12, 34, 76, 44};

void presente(int n, int p)
{
    if(p > 10){
        printf("Não encontrou %d\n", n);
        return;
    }
    if (v[p] == n)
    {
        printf("Encontrou %d na posição %d\n", n, p);
        return;
    }

    presente(n, ++p);
}

int main()
{
    presente(75, 0);
}