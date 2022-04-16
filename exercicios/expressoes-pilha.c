#include <stdio.h>
#include "../stack/stack.c"

int estaBalanceada(char exp[]){
    int s = sizeof(exp) / sizeof(exp[0]);
    for (int i = 0; i < s; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            //push()
        }
    }
    return 0;
}

int main(){
    char exp[] = "{10+[40*3(8+5)]}";

    if(estaBalanceada(exp)){
        printf("Está balanceada");
    }else{
        printf("Não está balanceada");
    }
    return 0;
}