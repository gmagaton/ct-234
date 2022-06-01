#include <stdio.h>
#include <string.h>

int bruteForceSearch(char* p, char* t){
    int n = strlen(t);
    int m = strlen(p);

    int j = 0;
    for (int i = 0; i <= n-m; i++)
    {
        j = 0;
        while(j<m && t[i+j] == p[j]){
            j++;
        }
        if(j == m){
            return i;
        }
    }
    
    return -1;
}

int main()
{
    char t[] = "ABAACAADAABAAABAA";
    char p[] = "AABA";
    int i = bruteForceSearch(p, t);

    printf("Palavra %s encontrada no indice %d", p, i);
    
    return 0;
}