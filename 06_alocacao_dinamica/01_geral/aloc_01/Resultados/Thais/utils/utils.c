#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

/**
 * Cria um vetor de inteiros de tamanho especificado, alocado dinamicamente.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
int *CriaVetor(int tamanho){
    //char* string = malloc(5 * sizeof(char)); //LEAK: not freed!

    int *vet = malloc(tamanho * sizeof(int));
    return vet;
}

/**
 * Lê um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(int *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        scanf("%d", (vetor + i));
    }
}

/**
 * Calcula a média dos valores de um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
float CalculaMedia(int *vetor, int tamanho){
    float media = 0;
    int i;
    for(i = 0; i < tamanho; i++){
        media += *(vetor + i);
    }
    media = media / (float)tamanho;
    return media;
}

/**
 * Libera a memória alocada para um vetor de inteiros.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(int *vetor){
    free(vetor);
}
