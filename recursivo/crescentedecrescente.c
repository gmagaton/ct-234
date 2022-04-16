#include <stdio.h>

/*
1) Escreva um algorítmo recursivo que imprima 1.n e n.1
Exemplo:
n = 10
imprimir: 10 9 8 7 6 5 4 3 2 1 1 2 3 4 5 6 7 8 9 10
*/
void prn(int n)
{
    if (n == 0)
        return;
    printf("%d ", n);
    prn(n - 1);
    printf("%d ", n);
}

int main()
{
    prn(10);
    return 0;
}