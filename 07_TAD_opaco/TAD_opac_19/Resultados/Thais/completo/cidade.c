#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"
#include "defesa.h"
#include "missil.h"

#define MAX_NOME 10 /**< Tamanho máximo do nome da cidade. */

#define QTD_DEF 10 /**< Quantidade máxima de defesas que uma cidade pode ter. */
#define QTD_MIS 10 /**< Quantidade máxima de mísseis que uma cidade pode ter. */

#define ENCERRAR 'F' /**< Caractere que indica o fim da entrada. */
#define MISSIL 'M' /**< Caractere que indica um míssil. */
#define DEFESA 'D' /**< Caractere que indica uma defesa. */

/**
 * @brief Estrutura que representa uma cidade.
 * 
 * A estrutura tCidade contém o nome da cidade, a quantidade de mísseis e defesas, e as listas de mísseis e defesas.
 * 
 */
typedef struct cidade * tCidade;

struct cidade{
    char *nome;
    int qtdMis, qtdDef;
    tMissil *missil;
    tDefesa *defesa;
    float efetividade;
    float danoMitigado, danoPossivel;
};

/**
 * @brief Cria uma nova cidade.
 * 
 * @return tCidade Ponteiro para a cidade criada.
 */
tCidade CriaCidade(){
    tCidade c = malloc(sizeof(struct cidade));
    if(c == NULL){
        printf("Falha");
        exit(EXIT_FAILURE);
    }
    c->missil = malloc(QTD_MIS * sizeof(struct missil *));
    if(c->missil == NULL){
        printf("Falha");
        exit(EXIT_FAILURE);
    }
    c->defesa = malloc(QTD_DEF * sizeof(struct defesa*));
    if(c->defesa == NULL){
        printf("Falha");
        exit(EXIT_FAILURE);
    }
    c->qtdDef = 0;
    c->qtdMis = 0;
    c->efetividade = 0; 
    c->danoMitigado = 0;
    c->danoPossivel = 0;
    return c;
}

/**
 * @brief Lê a entrada do usuário e preenche a cidade com as informações lidas.
 * 
 * @param cidade Ponteiro para a cidade que será preenchida.
 * @return tCidade Ponteiro para a cidade preenchida.
 */
tCidade LeEntrada(tCidade cidade){
    float x, y;
    char c;
    int i;
    scanf("C %f %f", &x, &y);

    while(1){
        scanf("%c", &c);
        if(c == ENCERRAR) break;
        else if(c == DEFESA){
            cidade->defesa[cidade->qtdDef] = LeDefesa();
            cidade->qtdDef++;
        }
        else if(c == MISSIL){
            cidade->missil[cidade->qtdMis] = LeMissil();
            cidade->qtdMis++;
        }
    }
    return cidade;
}

/**
 * @brief Imprime as informações da cidade.
 * 
 * @param cidade Ponteiro para a cidade que será impressa.
 */
void ImprimeCidade(tCidade cidade){
    //
    printf("OLA\n");
}

/**
 * @brief Libera a memória alocada para a cidade.
 * 
 * @param cidade Ponteiro para a cidade que terá a memória liberada.
 */
void LiberaCidade(tCidade cidade){
    int i;
    if(cidade != NULL){
        if(cidade->defesa != NULL){
            for(i = 0; i < cidade->qtdDef; i++){
                LiberaDefesa(cidade->defesa[i]);
            }
            free(cidade->defesa);
        }
        if(cidade->missil != NULL){
            for(i = 0; i < cidade->qtdMis; i++){
                LiberaMissil(cidade->missil[i]);
            }
            free(cidade->missil);
        }
        free(cidade);
    }
}

/**
 * @brief Processa os ataques na cidade.
 * 
 * @param cidade Ponteiro para a cidade que será atacada.
 */
void ProcessaAtaques(tCidade cidade){
    int i, j;
    float poder = 0;
    for(j = 0; j < cidade->qtdMis; j++){    
        cidade->danoPossivel += GetMissilPoder(cidade->missil[j]);
        for(i = 0; i < cidade->qtdDef; i++){
            if(VerificaSeDentroArea(cidade->defesa[i], GetMissilX(cidade->missil[j]), GetMissilY(cidade->missil[j]))){
                poder = GetMissilPoder(cidade->missil[j]);
                if(PodeDefender(cidade->defesa[i])){
                    ReduzPoder(cidade->missil[j], GetDefesaPoder(cidade->defesa[i]));
                    UsaDefesa(cidade->defesa[i]);
                }
                cidade->danoMitigado += poder - GetMissilPoder(cidade->missil[j]);
            }
        }
    }
    cidade->efetividade = cidade->danoMitigado / cidade->danoPossivel;
    cidade->efetividade = cidade->efetividade * 100;
}

/**
 * @brief Imprime os dados finais da cidade.
 * 
 * @param cidade Ponteiro para a cidade que terá os dados impressos.
 */
void ImprimeDados(tCidade cidade){
    int i;
    for(i = 0; i < cidade->qtdDef; i++){
        ImprimeDefesa(cidade->defesa[i]);
    }
    for(i = 0; i < cidade->qtdMis; i++){
        ImprimeMissil(cidade->missil[i]);
    }
    printf("Efetividade: %.2f%%\n", cidade->efetividade);
}
