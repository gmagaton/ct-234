#include <stdio.h>

/*
Complexidade de tempo:

T(1) = a
T(n) = T(n-1) + b

T(2) = T(1) + b = a + b
T(3) = T(2) + b = a + b + b = a + 2b
T(4) = T(3) + b = a + 3b

Generalizando
T(n) = a + (n-1)b
Portanto T(n) = Theta(n)
*/
int somaDigitos(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if(n < 0) n = n * -1;
    return n%10 + somaDigitos(n/10); //resto da divisão + empilhamento + desemplilhamento
}

int main()
{
    int n = 46607
    ;
    int r = somaDigitos(n);
    printf("A soma recursiva dos dígitos %d é %d", n, r);
    return 0;
}
