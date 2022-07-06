#include <stdio.h>

int V[] = {6,9,15,0,-7,9,4};

void printArray(int max)
{
    for (int i = 0; i < max; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void sift(int i, int n)
{
    int j = i;
    while (2 * j + 1 <= n)
    {
        int f = 2 * j + 1;
        // verifica se o filho a esquerda é maior que a raiz
        if (f <= n && V[f] < V[f + 1])
        {
            f = f + 1;
        }
        // verifica se o filho direito é maior que a raiz ou que o esquerdo
        if (V[j] >= V[f])
        {
            j = n;
        }
        else
        {
            int aux = V[j];
            V[j] = V[f];
            V[f] = aux;
        }
    }
}

void build(int n)
{
    // montar o heap de |n -1 / 2| até 0
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        sift(i, n);
        printArray(n);
    }
    printf("build pronto\n");
}

void heapsort(int n)
{
    build(n);
    
    for (int i = n - 1; i > 0; i--)
    {
        int aux = V[i];
        V[i] = V[0];
        V[0] = aux;

        sift(0, i - 1);
        printArray(n);
    }
}

int main()
{
    int N = sizeof(V) / sizeof(V[0]);
    printf("N = %d\n", N);
    printArray(N);
    heapsort(N);
    printf("Pronto\n");
    printArray(N);
    return 0;
}
