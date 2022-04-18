#include <stdio.h>

int N = 10;
int V[] = {11, 80, 6, 8, 10, 5, 50, 23, 22, 2}; // aleatorio
int VX[10];
// int V[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // crescente
// int V[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // decrescente

void printArray()
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void printArrayAux()
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", VX[i]);
    }
    printf("\n");
}

void merge(int i, int m, int f)
{
    int i1 = i;
    int i2 = i;
    int i3 = m + 1;
    while (i2 <= m && i3 <= f)
    {
        if (V[i2] < V[i3])
        {
            VX[i1++] = V[i2++];
        }
        else
        {
            VX[i1++] = V[i3++];
        }
    }
    while (i2 <= m)
    {
        VX[i1++] = V[i2++];
    }
    while (i3 <= f)
    {
        VX[i1++] = V[i3++];
    }
    for (int j = i; j <= f; j++)
    {
        V[j] = VX[j];
    }
}

void mergeSort(int i, int f)
{
    if (i < f)
    {
        int m = (i + f) / 2;
        //printf("mergeSort L i: %d m: %d\n", i, m);
        mergeSort(i, m);
        //printf("mergeSort R m: %d f: %d\n", m + 1, f);
        mergeSort(m + 1, f);
        //printf("merge i: %d m:%d f:%d\n", i, m, f);
        merge(i, m, f);
        printArrayAux();
    }
}

int main()
{
    printArray();
    mergeSort(0, N - 1);
    printArray();
    return 0;
}