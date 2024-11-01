#include <stdio.h>

int tamanhoRecursivoString(char str[]){
    if(str[0] == '\0')
        return 0;
    
    return 1 + tamanhoRecursivoString(str+1);
}

int main(){
    char string[100];

    scanf("%s", string);
    printf("%s ", string);

    int i;

    printf("%s tamanho %d\n", string, tamanhoRecursivoString(string));
}