#include <stdio.h>

int V[10];
int N = 10;
int f = 0;
int r = 0;

int size()
{
    int s = (N-f+r) % N;
    //printf("Size is %d\n", s);
    return s;
}

int isEmpty()
{
    return f == r ? 1 : 0;
}

int first()
{
    if (isEmpty())
    {
        printf("ERROR: Queue is empty\n");
        return -1;
    }
    return V[f];
}

int last()
{
    if (isEmpty())
    {
        printf("ERROR: Queue is empty\n");
        return -1;
    }
    return V[r-1];
}

void enqueue(int x)
{
    if (size() == N -1)
    {
        printf("ERROR: Queue is full\n");
        return;
    }
    V[r] = x;
    r = (r + 1) % N;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("ERROR: Queue is empty\n");
        return -1;
    }
    int x = V[f];
    V[f] = NULL;
    f = (f + 1) % N;
    return x;
}

void printVector(){
    for(int i = 0; i< N; i++){
        printf("%d ", V[i]);
    }
    printf("\n");
}