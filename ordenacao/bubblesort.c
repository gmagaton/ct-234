#include <stdio.h>

int N = 10;
// int V[] = {11, 80, 6, 8, 10, 5, 50, 23, 22, 2}; //aleatorio
// int V[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // crescente
int V[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // decrescente

void printArray()
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void bubbleSort()
{
    int c = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            c++;
            if (V[j] > V[j + 1])
            {
                int x = V[j];
                V[j] = V[j + 1];
                V[j + 1] = x;
            }
        }
    }
}

int main()
{
    printArray();
    bubbleSort();
    printArray();
    return 0;
}