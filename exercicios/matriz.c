
#include <stdio.h>
int V1[5][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16},
    {17, 18, 19, 20}};

int V2[4][1] = {
    {10},
    {11},
    {12},
    {13}};

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