#include <stdio.h>

int V[10];
int N = 10;
int t = -1; //-1 vazio

int size()
{
    return t + 1;
}

int isEmpty()
{
    return t < 0 ? 1 : 0;
}

void push(int value)
{
    if (size() == N)
    {
        printf("ERROR: Arrays is full\n");
        return;
    }
    //printf("STACK: adicionando %d na pilha\n", value);
    V[++t] = value;
}

int pop()
{
    if (isEmpty())
    {
        printf("ERROR: Array is empty\n");
        return -1;
    }
    int x = V[t--];
    // V[p] = NULL;
    return x;
}

int top()
{
    if (isEmpty())
    {
        printf("ERROR: Array is empty\n");
        return -1;
    }
    return V[t];
}