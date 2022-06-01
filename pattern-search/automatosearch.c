#include <stdio.h>
#include <string.h>

void printAF(int TF[][3], int M)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 97; j <= 99; j++)
        {
            if (TF[i][j] != 0)
                printf("AF [%d][%c] = %d\n", i, j, TF[i][j]);
        }
    }
}

void AFContruct(char *pat, int M, int TF[][3])
{
    int state, x, k;
    for (state = 0; state <= M; ++state)
        for (x = 97; x <= 99; ++x)
        {
            k = state + 2 <= M + 1 ? state + 2 : M + 1;
            do
            {
                k--;
            } while (pat[k - 1] == pat[state - 1]);
            TF[state][x] = k;
        }

    printAF(TF, M);
}

void AFMatch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int TF[M + 1][3];

    AFContruct(pat, M, TF);

    int i, state = 0;
    for (i = 0; i < N; i++)
    {
        state = TF[state][txt[i]];
        if (state == M)
            printf("\n Pattern found at index %d",
                   i - M + 1);
    }
}

int main()
{
    char *txt = "abababacaba";
    char *pat = "bacabacb";
    AFMatch(pat, txt);
    return 0;
}