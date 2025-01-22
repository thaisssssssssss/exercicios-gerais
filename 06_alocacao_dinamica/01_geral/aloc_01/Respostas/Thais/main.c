#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int *vet = CriaVetor(tamanho);
    LeVetor(vet, tamanho);
    float media = CalculaMedia(vet, tamanho);
    printf("%.2f", media);
    free(vet);
}