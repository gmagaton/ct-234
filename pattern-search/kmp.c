#include <stdio.h>
#include <string.h>

int count = 0;

void failureFunction(char *p, int M, int *F)
{
    F[0] = 0;
    int i = 1;
    int j = 0;

    while (i < M)
    {
        if (p[i] == p[j])
        {
            F[i++] = ++j;
        }
        else
        {
            if (j == 0)
            {
                F[i++] = 0;
            }
            else
            {
                j = F[j - 1];
            }
        }
    }
}

int kmp(char *t, char *p)
{
    int M = strlen(p);
    int N = strlen(t);

    int F[M];
    failureFunction(p, M, F);

    int i = 0;
    int j = 0;

    while (i < N)
    {
        count++;
        printf("Comparando %c com %c i=%d j=%d comp=%d\n", t[i], p[j], i+1, j, count);
        if (t[i] == p[j])
        {
            if (j == M - 1)
            {
                return i - j;
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            if (j != 0)
            {
                j = F[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return -1;
}

int main()
{
    char t[] = "Vi na mata uma arara e duas aranhas";
    char p[] = "araras";
    int i = kmp(t, p);

    printf("Palavra %s encontrada no indice %d com %d comparações", p, i+1, count);

    return 0;
}