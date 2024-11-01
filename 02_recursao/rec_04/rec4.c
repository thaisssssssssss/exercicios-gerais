#include <stdio.h>
#include <string.h>

int tamanhoRecursivoString(char *str, int tam, int a){
    if(tam <= a)
        return 1;
    else{

        if(str[tam] != str[a]){
            return 0;
        }
        return tamanhoRecursivoString(str, tam-1, a+1);
    
    }
}



int main(){
    char string[100];
    int tam;

    scanf("%s", string);
    
    for(tam = 0; string[tam]; tam++);
    printf("%d", tam);

    int palindromo = tamanhoRecursivoString(string, tam - 1, 0);
    printf("%s tamanho %d\n", string, palindromo);
}