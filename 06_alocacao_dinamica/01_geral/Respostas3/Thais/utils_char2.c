#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char2.h"
#include <assert.h>

/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao(){
    char *vet;
    vet = malloc(TAM_PADRAO * sizeof(char));
    assert(vet != NULL);
    int i;
    for(i = 0; i < TAM_PADRAO; i++){
        vet[i] = '_';
    }
    return vet;
}



/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 * 
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    char *NewVetor;
    //printf("%d", tamanhoantigo);

    NewVetor = realloc(vetor, (tamanhoantigo + TAM_PADRAO) * sizeof(char));
    //LiberaVetor(vetor);

    //tamanhoantigo = tamanhoantigo + TAM_PADRAO;
    return NewVetor;
}

/**
 * Lê uma string do tamanho especificado até um enter ser apertado.
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa
 * saiba o novo tamanho do vetor.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho* Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor.
 * @return Um ponteiro para o vetor lido.
*/
char* LeVetor(char *vetor, int *tamanho){
    scanf("%[^\n]", vetor);
    int i;
    for(i = 0; vetor[i]; i++){
        if(i != 0 && i % 10 == 0){
            AumentaTamanhoVetor(vetor, *tamanho);   
            *tamanho =  *tamanho + TAM_PADRAO;
        } 
    }
    return vetor;
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser imprimido.
*/
void ImprimeString(char *vetor){
    printf("%s", vetor);
    int i;
    for(i = 0; vetor[i]; i++);
    int resto = i % 10;
    resto = 10 - resto;
    for(i = 0; i < resto; i++){
        printf("_");
    }
    //printf("\n");
    //printf("(%d)\n", i);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor){
    free(vetor);
}

