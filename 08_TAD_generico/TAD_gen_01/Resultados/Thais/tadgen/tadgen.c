#include <stdlib.h>
#include <stdio.h>
#include "tadgen.h"

typedef struct generic tGeneric;

struct generic{
    void **vetor;
    int qtd;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    
    tGeneric *g = malloc(sizeof(tGeneric));
    void **vetor;
    int i;
    switch (type) {
        case INT:
            vetor = malloc(numElem * sizeof(int*));
            g->vetor = vetor;
            for(i = 0; i < numElem; i++){
                g->vetor[i] = malloc(sizeof(int));
            }
            g->tipo = 1;
        break;

        case FLOAT:
            vetor = malloc(numElem * sizeof(float*));
            g->vetor = vetor;
            for(i = 0; i < numElem; i++){
                g->vetor[i] = malloc(sizeof(float));
            }   
            g->tipo = 0;     
        break;
      }
      g->qtd = numElem;
      return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    int i;
    if(gen != NULL){
        if(gen->vetor != NULL){
            for(i = 0; i < gen->qtd; i++){
                if(gen->vetor[i] != NULL) free(gen->vetor[i]);
            }
            free(gen->vetor);
        }
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    int i;
    printf("\nDigite o vetor:\n");
    switch (gen->tipo) {
        case INT:
            for(i = 0; i < gen->qtd; i++){
                scanf("%d", (int*)gen->vetor[i]);
            }
        break;

        case FLOAT:
            for(i = 0; i < gen->qtd; i++){
                scanf("%f", (float*)gen->vetor[i]);
            }
        break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    int i;
    switch (gen->tipo) {
        case INT:
            for(i = 0; i < gen->qtd; i++){
                printf("%d ", *(int*)gen->vetor[i]);
            }
        break;

        case FLOAT:
            for(i = 0; i < gen->qtd; i++){
                printf("%.2f ", *(float*)gen->vetor[i]);
            }
        break;
    }
}

