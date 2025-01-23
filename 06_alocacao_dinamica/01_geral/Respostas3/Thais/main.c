//usar realloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char2.h"

int main(){
    char *vet;
    int tam;
    tam = TAM_PADRAO;
    vet = CriaVetorTamPadrao();
    vet = LeVetor(vet, &tam);
    ImprimeString(vet);
    LiberaVetor(vet);
    return 0;
}