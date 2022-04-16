#include "../stack/stacklinkedlist.c"

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("Stack size is %d\n", size());
    printf("Stack top is %d\n", top());

    pop();
    pop();
    pop();
    pop();
    pop();

    printf("Stack size is %d\n", size());
    printf("Stack top is %d\n", top());

    return 0;
}