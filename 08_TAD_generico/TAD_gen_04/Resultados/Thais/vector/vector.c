#include <stdio.h>
#include <stdlib.h>
typedef void *DataType; // void pointer
typedef struct Vector Vector;

struct Vector{
    DataType *data;
    int qtd;
    int max;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *v = malloc(sizeof(Vector));
    if(v == NULL) exit(EXIT_FAILURE);

    v->max = 10;
    v->qtd = 0;
    v->data = malloc(v->max * sizeof(DataType));
    if(v->data == NULL) exit(EXIT_FAILURE);

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
        v->data = realloc(v->data, v->max * sizeof(DataType));
        if(v->data == NULL) exit(EXIT_FAILURE);
        //v->data[v->qtd] = malloc(sizeof(void));
        v->data[v->qtd] = val;
        v->qtd++;
    }
    else{
        //v->data[v->qtd] = malloc(sizeof(void));
        v->data[v->qtd] = val;
        v->qtd++;
    }
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->data[i];
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
        if(v->data != NULL){
            int i;
            for(i = 0; i < v->qtd; i++) {
                if(v->data[i] != NULL) (*destroy)(v->data[i]);
            }
            free(v->data);
        }
        free(v);
    }
}

