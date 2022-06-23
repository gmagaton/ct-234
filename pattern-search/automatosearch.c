#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
}

char* substring(char *destination, const char *source, int beg, int n)
{
    // extracts `n` characters from the source string starting from `beg` index
    // and copy them into the destination string
    while (n > 0)
    {
        *destination = *(source + beg);
 
        destination++;
        source++;
        n--;
    }
 
    // null terminate destination string
    *destination = '\0';
 
    // return the destination string
    return destination;
}

// void printAF(int TF[][3], int M)
// {
//     for (int i = 0; i < M; i++)
//     {
//         for (int j = 97; j <= 99; j++)
//         {
//             if (TF[i][j] != 0)
//                 printf("AF [%d][%c] = %d\n", i, j, TF[i][j]);
//         }
//     }
// }

void AFContruct(char *pat, int M, int TF[][3])
{
    int state, x, k;
    for (state = 0; state <= M; state++)
        // alfabeto {a,b,c}
        for (x = 97; x <= 99; x++)
        {
            k = min(state + 2, M + 1);
            char a[M], b[M];
            do
            {
                k--;
                substring(a, pat, 0, k);
                substring(b, pat, 0, state);
            } while (a == b);
            TF[state][x] = k;
        }

    // printAF(TF, M);
}

int AFMatch(char *pat, char *txt)
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
        {
            return i - M + 1;
        }
    }
    return -1;
}

int main()
{
    char *txt = "abababacaba";
    char *pat = "ababaca";
    int i = AFMatch(pat, txt);
    printf("Pattern found at index %d", i);
    return 0;
}