#include <stdio.h>

int v[] = {10, 50, 43, 87, 33, 23, 12, 34, 76};
int n = 9;

void inverterVetor(int i, int f)
{
    if (i > f)
    {
        return;
    }
    int x = v[i];
    v[i] = v[f];
    v[f] = x;
    inverterVetor(i + 1, f - 1);
}

void printVetor()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    printVetor();
    inverterVetor(0,n-1);
    printVetor();
}