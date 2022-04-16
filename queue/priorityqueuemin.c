#include <stdio.h>

int V[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

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
    if (l <= n && V[l] < V[m] && V[l] != -1)
    {
        m = l;
    }
    // verifica se o filho direito é maior que a raiz ou que o esquerdo
    if (r <= n && V[r] < V[m] && V[r] != -1)
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

int min()
{
    if (size <= 0)
    {
        printf("ERROR: array is empty");
        return -1;
    }
    return V[0];
}

int extractMin()
{
    if (size <= 0)
    {
        printf("ERROR: Queue is empty");
        return -1;
    }

    int m = V[0];
    V[0] = V[size - 1];
    V[size - 1] = -1;
    size--;
    sift(0, size);
    return m;
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
    while (k > 0 && V[(k - 1) / 2] > V[k])
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
    printf("Min: %d\n", min());

    printf("Size: %d\n", size);
    printf("Extract Min: %d\n", extractMin());

    printf("Size: %d\n", size);

    printArray();

    return 0;
}
