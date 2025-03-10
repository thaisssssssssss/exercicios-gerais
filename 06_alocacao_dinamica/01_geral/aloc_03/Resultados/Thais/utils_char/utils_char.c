#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char.h"

/**
 * Cria um vetor de caracteres de tamanho especificado, alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas posições com "_"
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetor(int tamanho){
    char *vet;
    vet = malloc(tamanho * sizeof(char));
    int i;
    for(i = 0; i < tamanho; i++){
        vet[i] = '_';
    }
    return vet;
}

/**
 * Lê uma string do tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(char *vetor, int tamanho){
    char string[tamanho];
    scanf("%*[^a-z^A-Z]");
    scanf("%[^\n]", string);
    //printf("(%s)\n", string);
    int i;
    for(i = 0; string[i]; i++){
        vetor[i] = string[i];
        //printf("v(%c)\n", string[i]);
        //printf("i(%d)\n", i);
        if(i == tamanho - 1) break;
    }
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
void ImprimeString(char *vetor, int tamanho){
    printf("%s\n", vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor){
    free(vetor);
}

