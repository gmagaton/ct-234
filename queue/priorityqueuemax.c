#include <stdio.h>

int V[10] = {};

int size = 0;

void printArray()
{
    int n = sizeof(V) / sizeof(V[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void sift(int i, int n)
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

        sift(m, n); //
    }
}

int max()
{
    if (size <= 0)
    {
        printf("ERROR: array is empty");
        return -1;
    }
    return V[0];
}

int extractMax()
{
    if (size <= 0)
    {
        printf("ERROR: Queue is empty");
        return -1;
    }

    int max = V[0];
    V[0] = V[size - 1];
    V[size - 1] = -1;
    size--;
    sift(0, size);
    return max;
}

void modify(int k, int x)
{
    
    if (k > size || k < 1)
    {
        printf("ERROR: Index error\n");
        return;
    }
    k--;
    V[k] = x;

    // consertar para cima
    while (k > 0 && V[(k - 1) / 2] < V[k])
    {
        int aux = V[k];
        V[k] = V[(k - 1) / 2];
        V[(k - 1) / 2] = aux;
        k = (k - 1) / 2;
    }

    // consertar para baixo
    sift(k, size);
}

void insert(int x)
{
    modify(++size, x);
}

int main()
{
    insert(10);
    insert(15);
    insert(8);

    printf("Size: %d\n", size);

    printArray();
    printf("Max: %d\n", max());

    printf("Size: %d\n", size);
    printf("Extract Max: %d\n", extractMax());

    printf("Size: %d\n", size);

    printArray();

    modify(3, 20);

    printArray();

    return 0;
}
