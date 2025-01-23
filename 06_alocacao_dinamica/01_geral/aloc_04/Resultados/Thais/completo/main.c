#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char2.h"

int main() {
    int tamanho = TAM_PADRAO;
    char *vetor = CriaVetorTamPadrao();
    
    //printf("Digite uma string: ");
    vetor = LeVetor(vetor, &tamanho);

    ImprimeString(vetor);

    LiberaVetor(vetor);

    return 0;
}
