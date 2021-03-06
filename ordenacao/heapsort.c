#include <stdio.h>

int V[] = {6, 9, 15, 0, -7, 9, 4};

void printArray(int max)
{
    for (int i = 0; i < max; i++)
    {
        printf("%d, ", V[i]);
    }
    printf("\n");
}

void siftRecursivo(int i, int n)
{

    int l = (2 * i) + 1; // filho a esquerda
    int r = (2 * i) + 2; // filho a direita
    int m = i;

    // verifica se o filho a esquerda é maior que a raiz
    if (l <= n && V[l] > V[m])
    {

        m = l;
    }
    // verifica se o filho direito é maior que a raiz ou que o esquerdo
    if (r <= n && V[r] > V[m])
    {

        m = r;
    }

    // se encontrou maior, troca
    if (m != i)
    {
        int aux = V[i];
        V[i] = V[m];
        V[m] = aux;

        siftRecursivo(m, n); //
    }
}

void siftIterativo(int i, int n)
{
    int m, l, r;
    m = i;

    do
    {
        if (m != i)
        {
            i = m;
        }
        l = (2 * i) + 1; // filho a esquerda
        r = (2 * i) + 2; // filho a direita
        // m = i;

        // verifica se o filho a esquerda é maior que a raiz
        if (l <= n && V[l] < V[m])
        {

            m = l;
        }
        // verifica se o filho direito é maior que a raiz ou que o esquerdo
        if (r <= n && V[r] < V[m])
        {

            m = r;
        }

        // se encontrou maior, troca
        if (m != i)
        {
            int aux = V[i];
            V[i] = V[m];
            V[m] = aux;
        }
    } while (m != i);
}

void sift(int i, int n)
{
    siftRecursivo(i, n);
    //siftIterativo(i, n);
}

void build(int n)
{
    // montar o heap de |n -1 / 2| até 0
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        //printf("Sift \n");
        sift(i, n);
        printArray(n);
    }

}

void heapsort(int n)
{
    build(n);
    printf("inicio heap \n");
    printArray(n);
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
    //printf("N = %d\n", N);
    printArray(N);
    heapsort(N);
    //printArray(N);
    return 0;
}
