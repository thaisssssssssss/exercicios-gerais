#include <stdio.h>

int tamanhoRecursivoString(char str[]){
    if(str[0] == '\0')
        return 0;
    
    return 1 + tamanhoRecursivoString(str+1);
}

int main(){
    char string[100];

    //canf("%s", string);
    //printf("%s ", string);

    int i;

    //for(i = 0; string[i]; i++);
    //printf("%d", i);

    //printf("%d\n", tamanhoString(string));

    char teste[10] = "teste";
    printf("%s tamanho %d\n", teste, tamanhoRecursivoString(teste));
}