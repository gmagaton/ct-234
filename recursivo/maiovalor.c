#include <stdio.h>

int v[] = {10, 50, 43, 87, 33, 23, 12, 34, 76, 44};

int maiovalor(int n, int p, int m)
{
    if(p == n){
        return m;
    }
    if (v[p] > m)
    {
        return maiovalor(n, p + 1, v[p]);
    }
    else
    {
        return maiovalor(n, p + 1, m);
    }
}

int main()
{
   int m = maiovalor(10, 0, 0);
   printf("Maior valor recursivo %d", m);
}