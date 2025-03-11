#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

typedef void *DataType; // void pointer
typedef struct Vector Vector;

struct Vector{
    DataType *vector;
    int max;
    int qtd;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *vetor = malloc(sizeof(struct Vector));
    if(vetor == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    vetor->max = 10;
    vetor->qtd = 0;
    vetor->vector = malloc(vetor->max * sizeof(DataType));
    if(vetor->vector == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    if(v->qtd == v->max){
        v->max += v->max;
        v->vector = realloc(v->vector, v->max * sizeof(DataType));
        if(v->vector == NULL){
            printf("Falha!");
            exit(EXIT_FAILURE);
        }
    }
    v->vector[v->qtd++] = val;
}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i){
    int j;
    for(j = i; j < v->qtd - 1; j++){
        v->vector[j] = v->vector[j + 1];
    }
    v->qtd--;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->vector[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if(v != NULL){
        if(v->vector != NULL){
            int i;
                for(i = 0; i < v->qtd; i++){
                    (destroy)(v->vector[i]);
                }
            free(v->vector);
        }
        free(v);
    }
}

