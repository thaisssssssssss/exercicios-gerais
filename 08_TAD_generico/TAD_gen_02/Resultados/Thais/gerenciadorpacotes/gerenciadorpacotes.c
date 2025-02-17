#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

typedef struct gerenciadorpacotes tGerenciador;

struct gerenciadorpacotes{
    tPacote **pacotes;
    int qtd;
    int max;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){
    tGerenciador *g = malloc(sizeof(struct gerenciadorpacotes));
    g->max = 10;
    g->pacotes = malloc(g->max * sizeof(struct pacote*));
    g->qtd = 0;
    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    if(geren->qtd == geren->max) {
        geren->max += 10;
        geren->pacotes = realloc(geren->pacotes, geren->max * sizeof(struct pacote*));
    }
    geren->pacotes[geren->qtd] = pac;
    geren->qtd++;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    int i;
    if(geren != NULL){
        if(geren->pacotes != NULL){
            for(i = 0; i < geren->qtd; i++){
                DestroiPacote(geren->pacotes[i]);
            }
            free(geren->pacotes);
        }
        free(geren);
    }
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    int i;
    for(i = 0; i < geren->qtd; i++){
        ImprimePacote(geren->pacotes[i]);
    }
}

