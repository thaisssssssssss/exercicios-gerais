#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char2.h"
#include <assert.h>

char *CriaVetorTamPadrao() {
    char *vet = malloc((TAM_PADRAO + 1) * sizeof(char));
    assert(vet != NULL);

    for (int i = 0; i < TAM_PADRAO; i++) {
        vet[i] = '_';
    }
    vet[TAM_PADRAO] = '\0';
    return vet;
}

char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo) {
    vetor = realloc(vetor, (tamanhoantigo + TAM_PADRAO + 1) * sizeof(char));
    assert(vetor != NULL);

    for (int i = tamanhoantigo; i < tamanhoantigo + TAM_PADRAO; i++) {
        vetor[i] = '_';
    }

    vetor[tamanhoantigo + TAM_PADRAO] = '\0';
    return vetor;
}

char *LeVetor(char *vetor, int *tamanho) {
    int length = 0, ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length == *tamanho - 1) { // -1 para o '\0'
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }
        vetor[length] = ch;
        length++;
    }
    //vetor[length] = '\0';
    return vetor;
}

void ImprimeString(char *vetor) {
    printf("%s\n", vetor);
}

void LiberaVetor(char *vetor) {
    free(vetor);
}
