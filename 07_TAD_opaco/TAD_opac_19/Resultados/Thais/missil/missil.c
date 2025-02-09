#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidade.h"
#include "defesa.h"
#include "missil.h"

#define MAX_TAM 100 /**< Tamanho máximo do nome do míssil. */

/**
 * @brief Estrutura que representa um míssil.
 * 
 * A estrutura tMissil contém o nome do míssil, as coordenadas x e y, e o poder de ataque.
 * 
 */
typedef struct missil * tMissil;

struct missil{
    char *nome;
    float x, y;
    float ataque;
};

/**
 * @brief Lê a entrada do usuário e cria um novo míssil.
 * 
 * @return tMissil Ponteiro para o míssil criado.
 */
tMissil LeMissil(){
    // M2 50.7 70.2 32.6
    tMissil m = malloc(sizeof(struct missil));
    if(m == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    char nome[MAX_NOME];
    scanf("%*[A-Z^a-z]");
    scanf("%s %f %f %f", nome, &m->x, &m->y, &m->ataque);
    //printf("(%s)\n", nome);

    m->nome = malloc(strlen(nome) * sizeof(char) + 1);
    if(m->nome == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(m->nome, nome);

    return m;
}

/**
 * @brief Imprime as informações do míssil.
 * 
 * @param missil Ponteiro para o míssil que será impresso.
 */
void ImprimeMissil(tMissil missil){
    // M-1: 0.00
    printf("M-%s: %.2f\n", missil->nome, missil->ataque);
}

/**
 * @brief Libera a memória alocada para o míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void LiberaMissil(tMissil missil){
    if(missil != NULL){
        if(missil->nome != NULL) free(missil->nome);
        free(missil);
    }
}

/**
 * @brief Obtém a coordenada y do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float GetMissilY(tMissil missil){
    return missil->y;
}

/**
 * @brief Obtém a coordenada x do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float GetMissilX(tMissil missil){
    return missil->x;
}

/**
 * @brief Obtém o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float GetMissilPoder(tMissil missil){
    return missil->ataque;
}

/**
 * @brief Reduz o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void ReduzPoder(tMissil missil, float valor){
    if(missil->ataque >= valor) missil->ataque -= valor;
    else missil->ataque = 0;
}

