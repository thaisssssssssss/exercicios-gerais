#include "franquia.h"
#include "partida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Constante que representa o time da casa.
 * 
 */
#define TIME_CASA 1

/**
 * @brief Constante que representa o time visitante.
 * 
 */
#define TIME_FORA 2

/**
 * @brief Estrutura que representa uma partida.
 * 
 * A estrutura partida contém informações sobre os times que jogaram e o vencedor da partida.
 * 
 */
struct partida{
    char *tFora;
    char *tCasa;
    int pTimeFora;
    int pTimeCasa;
};

/**
 * @brief Lê uma partida do teclado.
 * 
 * @return tPartida Retorna um ponteiro para a partida lida.
 */
tPartida LePartida(){
    char tFora[MAX_NOME];
    char tCasa[MAX_NOME];
    tPartida p = malloc(sizeof(tPartida));
    scanf("%s @ %s %d %d", tFora, tCasa, &p->pTimeFora, &p->pTimeCasa);
    p->tFora = malloc(strlen(tFora) * sizeof(char) + 1);
    p->tCasa = malloc(strlen(tCasa) * sizeof(char) + 1);
    strcpy(p->tFora, tFora);
    strcpy(p->tCasa, tCasa);
    //printf("(%s @ %s %d %d)\n", p->tFora, p->tCasa, p->pTimeFora, p->pTimeCasa);
    return p;
}

/**
 * @brief Libera a memória alocada para uma partida.
 * 
 * @param p Ponteiro para a partida a ser liberada.
 */
void LiberaPartida(tPartida p){
    if(p != NULL){
        if(p->tFora != NULL) free(p->tFora);
        if(p->tCasa != NULL) free(p->tCasa);
        free(p);
    }
}

/**
 * @brief Imprime as informações de uma partida.
 * 
 * @param p Ponteiro para a partida a ser impressa.
 */
void ImprimePartida(tPartida p){
    printf("\n\nNAO SEI\n\n");
}

/**
 * @brief Retorna o nome do time da casa.
 * 
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time da casa.
 */
char * GetTime1Partida(tPartida p){
    return p->tCasa;
}

/**
 * @brief Retorna o nome do time visitante.
 * 
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time visitante.
 */
char * GetTime2Partida(tPartida p){
    return p->tFora;
}

/**
 * @brief Retorna o vencedor da partida.
 * 
 * @param p Ponteiro para a partida.
 * @return int Retorna a constante que representa o vencedor da partida (TIME_CASA ou TIME_FORA).
 */
int GetVencedorPartida(tPartida p){
    if(p->pTimeCasa > p->pTimeFora){
        //printf("(%s) %d\n", p->tCasa, p->pTimeCasa);
        return TIME_CASA;
    } 
    else if(p->pTimeCasa < p->pTimeFora){
        return TIME_FORA;
        //printf("(%s) %d\n", p->tFora, p->pTimeFora);
    }
}
