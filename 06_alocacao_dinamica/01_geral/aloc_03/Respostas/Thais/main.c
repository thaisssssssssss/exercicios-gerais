#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char.h"

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    char *vet = CriaVetor(tamanho);
    ImprimeString(vet, tamanho);
    LeVetor(vet, tamanho);
    ImprimeString(vet, tamanho);
    LiberaVetor(vet);
    return 0;
}