#include <stdio.h>
#include "filme.h"

int main(){
    int resultado, c, i = 0;;
    //int *codigo = malloc(sizeof(int));
    int codigo[20];
    while(1){
        resultado = scanf("%d", &c);
        if(resultado != 1) break;
        
        codigo[i] = c;
        i++;
        //codigo = realloc(codigo, i * sizeof(int) + 2);
    }
    int j;
    for(j= 0; j < i; j++){
        printf("%d\n", codigo[j]);
    }
}