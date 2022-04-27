#include <stdio.h>

int N = 7;
int V[] = {2, 3, 6, 10, 5, 3, 4};

void printArray()
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

int partition(int left, int right)
{
    int p = V[left];
    int l = left + 1;
    int r = right;
    while (1 == 1)
    {
        while (l < r && V[l] < p)
            l++;
        while (r > left && V[r] >= p)
            r--;

        if (l >= r)
            break;

        int aux = V[l];
        V[l] = V[r];
        V[r] = aux;
        printArray();
    }
    V[left] = V[r];
    V[r] = p;
    printArray();
    return r;
}

void quickSort(int min, int max)
{
    while (min < max)
    {
        int p = partition(min, max);
        if (p - min < max - p)
        {
            quickSort(min, p - 1);
            min = p + 1;
        }
        else
        {
            quickSort(p + 1, max);
            max = p -1;
        }
    }
}

int main()
{
    printArray();
    quickSort(0, 6);
    printArray();
    return 0;
}