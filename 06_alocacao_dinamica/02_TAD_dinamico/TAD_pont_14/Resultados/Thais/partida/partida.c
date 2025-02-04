#include <stdio.h>
#include "franquia.h"
#include "partida.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Lê uma partida do teclado.
 * 
 * @return tPartida Retorna um ponteiro para a partida lida.
 */
tPartida LePartida(){
    // P NETS @ BUCKS 89 92
    char time1[MAX_NOME], time2[MAX_NOME];
    tPartida p = malloc(sizeof(struct partida));
    if(p == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    scanf("%*[^A-Z^a-z]");
    scanf("%s @ %s %d %d", time2, time1, &p->pontos2, &p->pontos1);
    p->time1 = malloc(strlen(time1) * sizeof(char) + 1);
    if(p->time1 == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(p->time1, time1);
    p->time2 = malloc(strlen(time2) * sizeof(char) + 1);
    if(p->time2 == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(p->time2, time2);
    return p;
}

/**
 * @brief Libera a memória alocada para uma partida.
 * 
 * @param p Ponteiro para a partida a ser liberada.
 */
void LiberaPartida(tPartida p){
    if(p != NULL){
        if(p->time1 != NULL) free(p->time1);
        if(p->time2 != NULL) free(p->time2);
        free(p);
    }
}

/**
 * @brief Imprime as informações de uma partida.
 * 
 * @param p Ponteiro para a partida a ser impressa.
 */
void ImprimePartida(tPartida p){
    printf("oq?\n");
}

/**
 * @brief Retorna o nome do time da casa.
 * 
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time da casa.
 */
char * GetTime1Partida(tPartida p){
    return p->time1;
}

/**
 * @brief Retorna o nome do time visitante.
 * 
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time visitante.
 */
char * GetTime2Partida(tPartida p){
    return p->time2;
}

/**
 * @brief Retorna o vencedor da partida.
 * 
 * @param p Ponteiro para a partida.
 * @return int Retorna a constante que representa o vencedor da partida (TIME_CASA ou TIME_FORA).
 */
int GetVencedorPartida(tPartida p){
    if(p->pontos1 >= p->pontos2) return TIME_CASA;
    else return TIME_FORA;
}
