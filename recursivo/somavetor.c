#include <stdio.h>

int v[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

int somavetor(int p)
{
    if(p > 10){
        return 0;
    }
    return v[p] + somavetor(p+1);
}

int main()
{
    int soma = somavetor(0);
    printf("Soma do vetor é %d", soma);
}