#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef void *DataType; // void pointer
typedef struct Vector Vector;

struct Vector{
    DataType *vetor;
    int qtd;
    int max;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *v = malloc(sizeof(struct Vector));
    if(v == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    v->qtd = 0;
    v->max = 10;

    v->vetor = malloc(v->max * sizeof(struct Vector));
    if(v->vetor == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    return v;
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
        v->vetor = realloc(v->vetor, v->max * sizeof(struct Vector));
        if(v == NULL){
            printf("Falha!");
            exit(EXIT_FAILURE);
        }
    }
    v->vetor[v->qtd++] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
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
        if(v->vetor != NULL){
            int i;
            for(i = 0; i < v->qtd; i++){
                (destroy)(v->vetor[i]);
            }
            free(v->vetor);
        }
        free(v);
    }
}

