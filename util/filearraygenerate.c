#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("arrays.txt", "w");
    if (file == NULL)
    {
        perror("arrays.txt does not exists");
        return 1;
    }

    for (int i = 1; i <= 10000000; i++)
        fprintf(file, "%d\n", rand());


    fclose(file);
    return 0;
}