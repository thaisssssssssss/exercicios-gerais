#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/**
 * @brief Lê uma sequência de inteiros da entrada padrão e os armazena em um array.
 * @param array Ponteiro para o array onde os inteiros serão armazenados.
 * @param tamanho O tamanho do array.
 */
void LeNumeros(int *array, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        scanf("%d", (array + i));
    }
}

/**
 * @brief Encontra o maior, o menor e a média dos valores em um array de inteiros.
 * @param array Ponteiro para o array de inteiros.
 * @param tamanho O tamanho do array.
 * @param maior Ponteiro para a variável que armazenará o maior valor.
 * @param menor Ponteiro para a variável que armazenará o menor valor.
 * @param media Ponteiro para a variável que armazenará a média dos valores.
 */
void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int i, aux = 0;
    *media = 0;
    for(i = 0; i < tamanho; i++){
        if(aux == 0){
            *maior = *(array + i);
            *menor = *(array + i);
            aux++;
        }
        *media += *(array + i);

        if(*(array + i) < *menor) *menor = *(array + i);
        if(*(array + i) > *maior) *maior = *(array + i);
    }
    *media = *media / tamanho;
}
