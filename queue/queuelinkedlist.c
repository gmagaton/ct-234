#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;
int s = 0;

int size()
{
    return s;
}

int isEmpty()
{
    return s == 0 ? 1 : 0;
}

int first()
{
    if (isEmpty())
    {
        printf("ERROR: Queue is empty\n");
        return -1;
    }
    return head->data;
}

int last()
{
    if (isEmpty())
    {
        printf("ERROR: Queue is empty\n");
        return -1;
    }
    return tail->data;
}

void enqueue(int x)
{
    s++;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int dequeue()
{
    if (head == NULL)
    {
        printf("ERROR: Queue is empty\n");
        return -1;
    }
    s--;
    struct Node *temp = head;
    int x = head->data;
    head = head->next;

    if (head == NULL)
    {
        tail = NULL;
    }
    free(temp);
    return x;
}

void printLinkedlist()
{
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *next = head;
    //if (next != NULL) {
        while (next != NULL)
        {
            printf("%d ", next->data);
            next = next->next;
        }
        printf("\n");
    // } else {
    //     printf("List is empty\n");
    // }
}