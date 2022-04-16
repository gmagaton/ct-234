#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int r = fibonacci(5);
    printf("Fibonacci de 5 é : %d\n", r);
    return 0;
}