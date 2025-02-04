#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carta.h"
#include <stdbool.h>

#define MAX_NOME 100

struct carta{
    int id;
    char *nome;
    int pM;
    int pF;
    int pG;
    int numVitorias;
};

/**
 * @brief Lê uma carta do usuário e retorna um ponteiro para ela.
 * @return Retorna um ponteiro para a carta lida.
 */
tCarta LeCarta(){
    char nome[51];
    tCarta c = malloc(sizeof(struct carta));
    if(c == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    scanf("%d", &c->id);
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", nome);
    scanf("%d %d %d", &c->pM, &c->pF, &c->pG);

    c->nome = malloc(strlen(nome) * sizeof(char) + 1);
    if(c->nome == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(c->nome, nome);
    c->nome[strlen(nome)] = '\0';
    c->numVitorias = 0;
    return c;
}

/**
 * @brief Libera a memória alocada para uma carta.
 * @param c Ponteiro para a carta a ser liberada.
 */
void LiberaCarta(tCarta c){
    if(c != NULL){
        if(c->nome != NULL){
            free(c->nome);
        }
        free(c);
    }
}

/**
 * @brief Imprime as informações de uma carta.
 * @param c Ponteiro para a carta a ser impressa.
 */
void ImprimeCarta(tCarta c){
    printf("%s\n", GetNomeCarta(c));
}

/**
 * @brief Retorna o ID de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o ID da carta.
 */
int GetIdCarta(tCarta c){
    return c->id;
}

/**
 * @brief Retorna o nome de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o nome da carta.
 */
char * GetNomeCarta(tCarta c){
    return c->nome;
}

/**
 * @brief Retorna o número de vitórias de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o número de vitórias da carta.
 */
int GetNumVitCarta(tCarta c){
    return c->numVitorias;
}

/**
 * @brief Retorna o valor de magia de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de magia da carta.
 */
int GetMagiaCarta(tCarta c){
    return c->pM;
}

/**
 * @brief Retorna o valor de ataque de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de ataque da carta.
 */
int GetAtaqueCarta(tCarta c){
    return c->pF;
}

/**
 * @brief Retorna o valor de fogo de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de fogo da carta.
 */
int GetFogoCarta(tCarta c){
    return c->pG;
}

/**
 * @brief Verifica se uma carta é válida.
 * @param c Ponteiro para a carta.
 * @return Retorna true se a carta é válida e false caso contrário.
 */
bool EhCartaValida(tCarta c){
    if(c->pM <= 30 && c->pF <= 30 && c->pG <= 30){
        if(c->pM + c->pF + c->pG <= 80) return true;
        else return false;
    }
    else return false;
}

/**
 * @brief Verifica se duas cartas possuem o mesmo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna true se as cartas possuem o mesmo ID e false caso contrário.
 */
bool EhMesmoIdCarta(tCarta c1, tCarta c2){
    if(c1->id == c2->id) return true;
    else return false;
}

/**
 * @brief Compara duas cartas pelo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaIdCarta(tCarta c1, tCarta c2){
    if(EhMesmoIdCarta(c1, c2)){
        printf("(iguais)\n");
        return 0;
    }
    else if(GetIdCarta(c1) < GetIdCarta(c2)) return -5;
    else if(GetIdCarta(c1) > GetIdCarta(c2)) return 5;
}

/**
 * @brief Compara duas cartas pelo valor de magia.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaMagiaCarta(tCarta c1, tCarta c2){
    if(GetMagiaCarta(c1) == GetMagiaCarta(c2)){
        printf("M(iguais)\n");
        return 0;
    }
    else if(GetMagiaCarta(c1) < GetMagiaCarta(c2)) return -2;
    else if(GetMagiaCarta(c1) > GetMagiaCarta(c2)) return 2;
}

/**
 * @brief Compara duas cartas pelo valor de ataque.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaAtaqueCarta(tCarta c1, tCarta c2){
    if(GetAtaqueCarta(c1) == GetAtaqueCarta(c2)){
        printf("A(iguais)\n");
        return 0;
    }
    else if(GetAtaqueCarta(c1) < GetAtaqueCarta(c2)) return -3;
    else if(GetAtaqueCarta(c1) > GetAtaqueCarta(c2)) return 3;
}

/**
 * @brief Compara duas cartas pelo valor de fogo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaFogoCarta(tCarta c1, tCarta c2){
    if(GetFogoCarta(c1) == GetFogoCarta(c2)){
        printf("F(iguais)\n");
        return 0;
    }
    else if(GetFogoCarta(c1) < GetFogoCarta(c2)) return -4;
    else if(GetFogoCarta(c1) > GetFogoCarta(c2)) return 4;
}

/**
 * @brief Adiciona uma vitória para uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o novo número de vitórias da carta.
 */
int AdicionaVitoriaCarta(tCarta c){
    c->numVitorias++;
    return c->numVitorias;
}
