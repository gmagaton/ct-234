#include <stdio.h>

void hanoi(int n, int org, int dest, int aux)
{
    if (n == 1)
        printf("Mova de %d para %d\n", org, dest);
    else
    {
        hanoi(n - 1, org, aux, dest);
        printf("Mova de %d para %d\n", org, dest);
        hanoi(n - 1, aux, dest, org);
    }
}

int main()
{
    hanoi(3, 1, 2, 3);
}