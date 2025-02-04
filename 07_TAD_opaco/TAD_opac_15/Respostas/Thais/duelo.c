#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duelo.h"
#include "carta.h"

/**
 * @brief Estrutura de dados que representa um duelo entre duas cartas.
 */
struct duelo{
    int id;
    //tCarta *carta1;
    //tCarta *carta2;
    int idCarta1;
    int idCarta2;
    char atributo;
    int diferenca;
    int vencedor;
};

#define MAGIA 'M' /**< Opção para duelo de magia. */
#define FORCA 'F' /**< Opção para duelo de força. */
#define FOGO 'G' /**< Opção para duelo de fogo. */

/**
 * @brief Lê um duelo do usuário.
 * @return Retorna um ponteiro para o duelo lido.
 */
tDuelo LeDuelo(){
    tDuelo d = malloc(sizeof(struct duelo));
    if(d == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    scanf("%d", &d->id);
    scanf("%d %d %c", &d->idCarta1, &d->idCarta2, &d->atributo);
    return d;
}

/**
 * @brief Libera a memória alocada para um duelo.
 * @param d Ponteiro para o duelo a ser liberado.
 */
void LiberaDuelo(tDuelo d){
    if(d != NULL) free(d);
}

/**
 * @brief Imprime as informações de um duelo.
 * @param d Ponteiro para o duelo a ser impresso.
 */
void ImprimeDuelo(tDuelo d){
    printf("NAO SEI\n");
}

/**
 * @brief Realiza um duelo entre duas cartas.
 * @param d Ponteiro para o duelo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 */
void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2){
    if(d->atributo == MAGIA){
        if(ComparaMagiaCarta(c1, c2) == 0){
            if(ComparaIdCarta(c1, c2) < 0){
                d->vencedor = GetIdCarta(c1);
                AdicionaVitoriaCarta(c1);
                d->diferenca = 0;
                //printf("diferenca(%d)\n", d->diferenca);
            }
            else if(ComparaIdCarta(c1, c2) > 0){
                d->vencedor = GetIdCarta(c2);
                AdicionaVitoriaCarta(c2);
                d->diferenca = 0;
                //printf("diferenca(%d)\n", d->diferenca);
            }
        }

        else if(ComparaMagiaCarta(c1, c2) < 0){
            d->vencedor = GetIdCarta(c2);
            AdicionaVitoriaCarta(c2);
            d->diferenca = GetMagiaCarta(c2) - GetMagiaCarta(c1);
            //printf("diferenca(%d)\n", d->diferenca);
        }
        else{
            d->vencedor = GetIdCarta(c1);
            AdicionaVitoriaCarta(c1);
            d->diferenca = GetMagiaCarta(c1) - GetMagiaCarta(c2);
        }
    }
    else if(d->atributo == FORCA){
        if(ComparaAtaqueCarta(c1, c2) == 0){
            if(ComparaIdCarta(c1, c2) < 0){
                d->vencedor = GetIdCarta(c1);
                AdicionaVitoriaCarta(c1);
                d->diferenca = 0;
            }
            else if(ComparaIdCarta(c1, c2) > 0){
                d->vencedor = GetIdCarta(c2);
                AdicionaVitoriaCarta(c2);
                d->diferenca = 0;
            }
        }
        else if(ComparaAtaqueCarta(c1, c2) < 0){
            d->vencedor = GetIdCarta(c2);
            AdicionaVitoriaCarta(c2);
            d->diferenca = GetAtaqueCarta(c2) - GetAtaqueCarta(c1);
        }
        else{
            d->vencedor = GetIdCarta(c1);
            AdicionaVitoriaCarta(c1);
            d->diferenca = GetAtaqueCarta(c1) - GetAtaqueCarta(c2);
        }
    }
    else if(d->atributo == FOGO){
        if(ComparaFogoCarta(c1, c2) == 0){
            if(ComparaIdCarta(c1, c2) < 0){
                d->vencedor = GetIdCarta(c1);
                AdicionaVitoriaCarta(c1);
                d->diferenca = 0;
            }
            else if(ComparaIdCarta(c1, c2) > 0){
                d->vencedor = GetIdCarta(c2);
                AdicionaVitoriaCarta(c2);
                d->diferenca = 0;
            }
        }
        else if(ComparaFogoCarta(c1, c2) < 0){
            d->vencedor = GetIdCarta(c1);
            AdicionaVitoriaCarta(c1);
            d->diferenca = GetFogoCarta(c1) - GetFogoCarta(c2);
            //printf("%d %d diferenca(%d)\n", GetFogoCarta(c2), GetFogoCarta(c1), d->diferenca);
        }
        else{
            d->vencedor = GetIdCarta(c2);
            AdicionaVitoriaCarta(c2);
            d->diferenca = GetFogoCarta(c2) - GetFogoCarta(c1);
            //printf("%d %d diferenca(%d)\n", GetFogoCarta(c2), GetFogoCarta(c1), d->diferenca);
        }
    }
            //printf("diferenca(%d)\n", d->diferenca);
}

/**
 * @brief Retorna o ID da primeira carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da primeira carta do duelo.
 */
int GetC1Duelo(tDuelo d){
    return d->idCarta1;
}

/**
 * @brief Retorna o ID da segunda carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da segunda carta do duelo.
 */
int GetC2Duelo(tDuelo d){
    return d->idCarta2;
}

/**
 * @brief Retorna se houve desempate no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna true se houve desempate e false caso contrário.
 */
bool GetDesempateDuelo(tDuelo d){
    if(d->diferenca == 0) return true;
    else return false;
}

/**
 * @brief Retorna a diferença de pontos entre as cartas no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna a diferença de pontos entre as cartas no duelo.
 */
int GetDiferencaDuelo(tDuelo d){
    //printf("diferenca(%d)\n", d->diferenca);
    return d->diferenca;
}

/**
 * @brief Retorna o ID do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID do duelo.
 */
int GetIdDuelo(tDuelo d){
    return d->id;
}
