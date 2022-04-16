#include "../queue/queuelinkedlist.c"

int main(){
    enqueue(1);
    enqueue(2);

    //printLinkedlist();

    printf("Queue size is %d\n", size());
    printf("Stack first is %d\n", first());
    printf("Stack last is %d\n", last());

    printf("Dequeue is %d\n", dequeue());
    printf("Dequeue is %d\n", dequeue());

    printf("Queue size is %d\n", size());
    printf("Stack first is %d\n", first());
    printf("Stack last is %d\n", last());

    printLinkedlist();

    return 0;
}