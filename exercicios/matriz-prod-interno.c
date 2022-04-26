
#include <stdio.h>
int V1[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};

int V2[3][3] = {
    {10, 10, 10},
    {10, 10, 10},
    {10, 10, 10}};

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

int produtointerno(int i)
{
    if (i == 0)
        return V1[i][i] * V2[i][i];
    return V1[i][i] * V2[i][i] * produtointerno(i - 1);
    //90 * 50 * 10 = 45000
}

int main()
{
    printMatrix(V1);
    printMatrix(V2);

    int x = produtointerno(2);

    printf("Produto interno é: %d\n", x);

    return 0;
}