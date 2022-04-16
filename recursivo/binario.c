#include <stdio.h>

void binario(int n){
    if(n == 1){
        printf("1");
        return;
    }
    binario(n/2);
    int r = n % 2;
    printf("%d", r);
}

int main (){
    binario(1024);
    return 0;
}