#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cidade.h"
#include "defesa.h"
#include "missil.h"

#define QUADRADO 'Q' /**< Caractere que indica uma defesa do tipo quadrado. */
#define CIRCULO 'C' /**< Caractere que indica uma defesa do tipo círculo. */
#define MAX_TAM 100 /**< Tamanho máximo do nome da defesa. */

/**
 * @brief Estrutura que representa uma defesa.
 * 
 * A estrutura tDefesa contém o tipo da defesa, as coordenadas do centro, o tamanho e o poder de defesa.
 * 
 */
typedef struct defesa * tDefesa;

struct defesa{
    char *nome;
    char tipo;
    float x, y;
    float tamanho;
    float poder;
    int qtd;
};

/**
 * @brief Lê a entrada do usuário e cria uma nova defesa.
 * 
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa LeDefesa(){
    //D2 93.1 69.0 C 28.30 42.6 8
    tDefesa d = malloc(sizeof(struct defesa));
    if(d == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    char nome[MAX_NOME];
    scanf("%*[A-Z^a-z]");
    scanf("%s %f %f %c %f %f %d", nome, &d->x, &d->y, &d->tipo, &d->tamanho, &d->poder, &d->qtd);
    d->nome = malloc(strlen(nome) * sizeof(char) + 1);
    if(d->nome == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(d->nome, nome);
    return d;
}

/**
 * @brief Imprime as informações da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa){
    // D-2: 7
    printf("D-%s: %d\n", defesa->nome, defesa->qtd);
}

/**
 * @brief Libera a memória alocada para a defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa){
    if(defesa != NULL){
        if(defesa->nome != NULL) free(defesa->nome);
        free(defesa);
    }
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa defesa, float x, float y){
    float dist = 0;
    if(defesa->tipo == CIRCULO){
        dist = pow(defesa->x - x, 2) + pow(defesa->y - y, 2);
        dist = sqrt(dist);
        if(dist <= defesa->tamanho) return 1;
        else return 0;
    }
    else if(defesa->tipo == QUADRADO){
        float lado = 0, x1, x2, y1, y2;
        //lado do quadrado
        lado = pow(defesa->tamanho * 2, 2);
        lado = lado / 2;
        lado = sqrt(lado);
        //lado = defesa->tamanho / sqrt(2);

        //x1 e x2
        x1 = defesa->x - (lado / 2);
        x2 = defesa->x + (lado / 2);

        //y1 e y2
        y1 = defesa->y - (lado / 2);
        y2 = defesa->y + (lado / 2);

        if((x >= x1 && x <= x2) && (y >= y1 && y <= y2)) return 1;
        else return 0;
    }
}

/**
 * @brief Usa a defesa, diminuindo seu poder de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa){
    if(defesa->qtd > 0) defesa->qtd--;
}

/**
 * @brief Obtém o poder de defesa da defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa){
    return defesa->poder;
}

/**
 * @brief Verifica se a defesa pode defender.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa){
    return (defesa->qtd > 0);
}

