#include "../queue/queue.c"

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    printVector();

    printf("Queue size is %d\n", size());
    printf("Stack front is %d\n", first());
    printf("Stack rear is %d\n", last());

    printf("Dequeue is %d\n", dequeue());
    printf("Dequeue is %d\n", dequeue());
    printf("Dequeue is %d\n", dequeue());
    printf("Dequeue is %d\n", dequeue());
    printf("Dequeue is %d\n", dequeue());
    printf("Dequeue is %d\n", dequeue());

    printVector();

    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    enqueue(12);

    printVector();

    printf("Queue size is %d\n", size());
    printf("Stack front is %d\n", first());
    printf("Stack rear is %d\n", last());

    return 0;
}