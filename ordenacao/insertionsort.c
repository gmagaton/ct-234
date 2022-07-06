#include <stdio.h>

int N = 10;
int V[] = {11, 80, 6, 8, 10, 5, 50, 23, 22, 2}; // aleatorio
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

void insertionSort()
{
    int i, x, j;
    for (i = 1; i < N; i++)
    {
        x = V[i];
        int j;
        for (j = i; j > 0 && x < V[j - 1]; j--)
        {
            V[j] = V[j - 1];
            
        }
        V[j] = x;
        
    }
}

int main()
{
    printArray();
    insertionSort();
    printArray();
    return 0;
}