#include <stdio.h>

int N = 20;
int V[] = {8, 5, 3, 9, 21, 22, 88, 75, 66, 45, 17, -100, 23, -3, 12, 20, -20, 30, 28, 32};

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
    }
    V[left] = V[r];
    V[r] = p;
    return r;
}

void quickSort(int min, int max)
{
    if (min < max)
    {
        int p = partition(min, max);
        quickSort(min, p - 1);
        quickSort(p + 1, max);
    }
}

int main()
{
    printArray();
    quickSort(0, 19);
    printArray();
    return 0;
}