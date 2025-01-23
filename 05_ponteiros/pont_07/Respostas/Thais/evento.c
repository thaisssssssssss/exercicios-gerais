#include <stdio.h>
#include <string.h>
#include "evento.h"

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos){
    int dia, mes, ano;
    char nome[50];
    scanf("%s", nome);
    scanf("%d %d %d", &dia, &mes, &ano);
    strcpy(eventos[*numEventos].nome, nome);
    eventos[*numEventos].dia = dia;
    eventos[*numEventos].mes = mes;
    eventos[*numEventos].ano = ano;
    *numEventos++;
    printf("Evento cadastrado com sucesso!\n");
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos){
    int i;
    for(i = 0; i < *numEventos; i++){
        printf("%d - %s - %02d/%02d/%04d\n", *numEventos, eventos[*numEventos].nome, eventos[*numEventos].dia, eventos[*numEventos].mes, eventos[*numEventos].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos){
    int n;
    scanf("%d", &n);
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    eventos[n].dia = dia;
    eventos[n].mes = mes;
    eventos[n].ano = ano;
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if(*indiceA >= *numEventos) printf("Indice invalido!\n");
    else if(*indiceB >= *numEventos) printf("Indice invalido!\n");
    else{
        Evento aux;
        aux = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = aux;
    }
}


