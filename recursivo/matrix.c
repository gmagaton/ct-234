#include <stdio.h>

int m1[3][3] = {
    {11, 12, 13},
    {11, 12, 13},
    {11, 12, 13}};

int m2[3][3] = {
    {11, 12, 13},
    {11, 12, 13},
    {11, 12, 13}};
int c[3][3];

void printMatrix(int m[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%d][%d]=%d ", i, j, m[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int x = 0; x < 3; x++)
            {
                c[i][j] +=  m1[i][x] * m2[x][j];
            }
        }
    }

    // nˆ3 = 1000

    // nˆ2,81 = 646
    // nˆ2,37 = 235


    printf("m1\n");
    printMatrix(m1);

    printf("m2\n");
    printMatrix(m2);

    printf("c\n");
    printMatrix(c);
}