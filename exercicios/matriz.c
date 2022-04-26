
#include <stdio.h>
int V1[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};

int V2[3][3] = {
    {10, 10, 10},
    {10, 10, 10},
    {10, 10, 10}};

int X[3][3];

int i = 0, j = 0, k = 0;

void printMatrix(int X[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%d,%d]: %d ", i, j, X[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mult()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            X[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                X[i][j] += V1[i][k] * V2[k][j];
            }
        }
    }
}

int main()
{
    printMatrix(V1);
    printMatrix(V2);

    mult();

    printMatrix(X);

    return 0;
}