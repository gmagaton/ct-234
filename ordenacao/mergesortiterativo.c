#include <stdio.h>
#include "../util/maxmin.c"

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

void mergeSortIterativo(int i, int f)
{
    int curr_size;  // For current size of subarrays to be merged
                    // curr_size varies from 1 to n/2
    int left_start; // For picking starting index of left subarray
                    // to be merged

    // Merge subarrays in bottom up manner.  First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.
    for (curr_size = 1; curr_size <= f; curr_size = 2 * curr_size)
    {
        // Pick starting point of different subarrays of current size
        for (left_start = 0; left_start < f; left_start += 2 * curr_size)
        {
            // Find ending point of left subarray. mid+1 is starting
            // point of right
            int mid = min(left_start + curr_size - 1, f);

            int right_end = min(left_start + 2 * curr_size - 1, f);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(left_start, mid, right_end);
        }
    }
}

int main()
{
    printArray();
    mergeSortIterativo(0, N - 1);
    printArray();
    return 0;
}