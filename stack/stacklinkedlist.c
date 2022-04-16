#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int i = -1;
struct Node *head = NULL;

int size()
{
    return i + 1;
}

int isEmpty()
{
    return i < 0 ? 1 : 0;
}

void push(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    i++;
}

int pop()
{
    if (isEmpty())
    {
        printf("ERROR: Stack is empty");
        return -1;
    }

    int v = head->data;
    struct Node *temp = head;

    head = head->next;
    free(temp);

    i--;
    return v;
}

int top()
{
    if (isEmpty())
    {
        printf("ERROR: Stack is empty\n");
        return -1;
    }
    return head->data;
}