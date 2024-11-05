#include <stdio.h>
#include <string.h>


int tamanhoRecursivoString(char *str, int tam, int a){
    if(tam <= a)
        return 1;
    else{
        if(str[tam] != str[a])
            return 0;

            return tamanhoRecursivoString(str, tam-1, a+1);
    }
}

int main(){
    char string[100];
    int recebe, tam;
    int palindromo;

    while(1){
        recebe = scanf("%s", string);

        if(recebe == -1 || recebe == 0){
            break;
        }

        for(tam = 0; string[tam]; tam++);
        palindromo = tamanhoRecursivoString(string, tam - 1, 0);
        if(palindromo == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        
    }
}