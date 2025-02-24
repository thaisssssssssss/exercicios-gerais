#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

typedef struct impr tImpr;

struct impr{
    char *mens;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr *imp = malloc(sizeof(struct impr));
    if(imp == NULL) exit(EXIT_FAILURE);

    imp->mens = malloc(strlen(msg) * sizeof(char) + 1);
    strcpy(imp->mens, msg);
    return imp;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    printf("\n%s", ((tImpr*)imp)->mens);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    if(((tImpr*)imp) != NULL){
        if(((tImpr*)imp)->mens != NULL) free(((tImpr*)imp)->mens);
        free(((tImpr*)imp));
    }
}

