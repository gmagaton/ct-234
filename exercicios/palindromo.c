#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../stack/stacklinkedlist.c"

bool palindromo(char *T)
{
    int tam = strlen(T);
    int m = tam / 2;

    for (int i = 0; i < m; i++)
    {
        push(T[i]);
    }

    if (tam % 2 == 1)
        m++;

    while (!isEmpty())
    {
        char c = top();
        pop();
        if (c != T[m]) return false;
        m++;
    }

    return true;
}

int main()
{
    char T[] = "arara";
    if (palindromo(T))
    {
        printf("É palindromo");
    }
    else
    {
        printf("Não é palindromo");
    }
    return 0;
}
