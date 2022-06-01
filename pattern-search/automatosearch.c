// C program for Finite Automata Pattern searching
// Algorithm
#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256

void printAF(int TF[][NO_OF_CHARS], int M)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < NO_OF_CHARS; j++)
        {
            if (TF[i][j] != 0)
                printf("AF [%d][%c] = %d\n", i, j, TF[i][j]);
        }
    }
}

int getNextState(char *pat, int M, int state, int x)
{
    if (state < M && x == pat[state])
        return state + 1;

    int ns, i;

    for (ns = state; ns > 0; ns--)
    {
        if (pat[ns - 1] == x)
        {
            for (i = 0; i < ns - 1; i++)
                if (pat[i] != pat[state - ns + 1 + i])
                    break;
            if (i == ns - 1)
                return ns;
        }
    }

    return 0;
}

/* This function builds the TF table which represents4
    Finite Automata for a given pattern */
void computeTF(char *pat, int M, int TF[][NO_OF_CHARS])
{
    int state, x;
    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
            TF[state][x] = getNextState(pat, M, state, x);

    printAF(TF, M);
}

/* Prints all occurrences of pat in txt */
void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int TF[M + 1][NO_OF_CHARS];

    computeTF(pat, M, TF);

    // Process txt over FA.
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
    search(pat, txt);
    return 0;
}