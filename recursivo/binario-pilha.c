#include <stdio.h>
#include "../stack/stack.c"

void binario(int n){
    if(n == 0){
        push(n);  
    }
    while(n > 0){
        push(n % 2);    
        n = n / 2;
    }
    while(!isEmpty()){
        printf("%d", top());
        pop();
    }
    
}

int main (){
    binario(0);
    return 0;
}