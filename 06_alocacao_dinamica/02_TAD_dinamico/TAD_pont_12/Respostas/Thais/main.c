#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(){
    int b, indice;
    Array *a = CriarArray();
    LerArray(a);
    scanf("%d", &b);
    OrdenarArray(a);
    indice = BuscaBinariaArray(a, b);
    if(indice == -1) printf("Elemento %d não encontrado no array (-1).\n", b);
    else printf("Elemento %d encontrado no índice %d.\n", b, indice);
    DestruirArray(a);
}