#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendatarefas.h"

typedef struct agendatarefas tAgendaTarefas;

struct agendatarefas{
    void **tarefas;
    int qtd;
    int inicio;
    int *prioridade;
    void (**executa)(void*);
    void (**destroi)(void*);
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas *t = malloc(sizeof(struct agendatarefas));
    t->tarefas = malloc(numElem * sizeof(void(*)(void*)));
    t->executa = malloc(numElem * sizeof(void(*)(void*)));
    t->destroi = malloc(numElem * sizeof(void*));
    t->qtd = numElem;
    t->inicio = 0;
    t->prioridade = malloc(numElem * sizeof(int));
    return t;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    int i;
    if(tar != NULL){
        if(tar->tarefas != NULL){
            for(i = 0; i < tar->qtd; i++){
                if(tar->tarefas[i] != NULL) (tar->destroi[i])(tar->tarefas[i]);
            }
            free(tar->tarefas);
        }
        if(tar->destroi != NULL && tar->executa != NULL){
            // for(i = 0; i < tar->qtd; i++){
            //     if(tar->destroi[i] != NULL) free(tar->destroi[i]);
            //     if(tar->executa[i] != NULL) free(tar->executa[i]);
            // }
            free(tar->destroi);
            free(tar->executa);
        }
        if(tar->prioridade != NULL) free(tar->prioridade);
        free(tar);
    }
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    tar->tarefas[tar->inicio] = tarefa;
    tar->prioridade[tar->inicio] = prioridade;
    tar->executa[tar->inicio] = (*executa);
    tar->destroi[tar->inicio] = (*destroi);
    tar->inicio++;
}   

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    int i, j, aux;
    void *auxT, *auxE, *auxD;

    for(i = 0; i < tar->qtd; i++){
        for(j = i; j < tar->qtd; j++){
            if(tar->prioridade[j] > tar->prioridade[i]){
                aux = tar->prioridade[i];
                tar->prioridade[i] = tar->prioridade[j];
                tar->prioridade[j] = aux;

                auxT = tar->tarefas[i];
                tar->tarefas[i] = tar->tarefas[j];
                tar->tarefas[j] = auxT;

                auxE = tar->executa[i];
                tar->executa[i] = tar->executa[j];
                tar->executa[j] = auxE;

                auxD = tar->destroi[i];
                tar->destroi[i] = tar->destroi[j];
                tar->destroi[j] = auxD;
            }
        }
    }

    for(i = 0; i < tar->qtd; i++){
        (tar->executa[i])(tar->tarefas[i]);
    }
}



