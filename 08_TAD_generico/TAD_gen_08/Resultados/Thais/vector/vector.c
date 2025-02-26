#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

typedef void *DataType; // void pointer
typedef struct Vector Vector;

struct Vector{
    void **vetor;
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
    v->max = 5;
    v->vetor = malloc(v->max * sizeof(void*));
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
        v->vetor = realloc(v->vetor, v->max * sizeof(void*));
        if(v->vetor == NULL){
            printf("Falha!");
            exit(EXIT_FAILURE);
        }
    }
    //memcpy(v->vetor[v->qtd], val, strlen(*(char*)val) + 1);
    v->vetor[v->qtd] = val;
    v->qtd++;
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v){
    int i;
    DataType aux = v->vetor[0];

    for(i = 0; i < v->qtd - 1; i++){
        v->vetor[i] = v->vetor[i + 1];
    }
    //free(v->vetor[v->qtd - 1]);
    v->qtd--;
    return aux;
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
                if(v->vetor[i] != NULL) (*destroy)(v->vetor[i]);
            }
            free(v->vetor);
        }
        free(v);
    }
}


