#include <stdio.h>
#include <stdlib.h>
#include "tarefasoma.h"

typedef struct soma tSoma;

struct soma{
    float n1, n2;
    float result;
};

/**
 * @brief Cria uma tarefa do tipo soma de dois números
 * 
 * @param n1 - Primeiro número que será somado quando a tarefa for executada
 * @param n2 - Segundo número que será somado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tSoma* CriaTarefaSoma(float n1, float n2){
    tSoma *soma = malloc(sizeof(struct soma));
    soma->n1 = n1;
    soma->n2 = n2;
    soma->result = 0;

    return soma;
}

/**
 * @brief Função que executa uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaSoma(void *sum){
    ((tSoma*)sum)->result = ((tSoma*)sum)->n1 + ((tSoma*)sum)->n2;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", ((tSoma*)sum)->n1, ((tSoma*)sum)->n2, ((tSoma*)sum)->result);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaSoma(void *sum){
    free ((tSoma*)sum);
}