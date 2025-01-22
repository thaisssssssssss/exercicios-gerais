#include <stdio.h>
#include "pessoa.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa){
    char nome[100];
    scanf("%*[^a-z^A-Z]");
    scanf("%[^\n]", nome);
    strcpy(pessoa->nome, nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->mae != NULL) return 1;
    else if(pessoa->pai != NULL) return 1;
    else return 0;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa){
    if(VerificaSeTemPaisPessoa(pessoa)) {
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        
        if(pessoa->mae != NULL){
            printf("MAE: %s\n", pessoa->mae->nome);
            //free(pessoa->mae);
        }
        else printf("MAE: NAO INFORMADO\n");

        if(pessoa->pai != NULL){
            printf("PAI: %s\n\n", pessoa->pai->nome);
            //free(pessoa->pai);
        } 
        else printf("PAI: NAO INFORMADO\n\n");
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int qtd, i, mae, pai, filho;
    scanf("%d", &qtd);
    //printf("(%d)\n", qtd);
    for(i = 0; i < qtd; i++){
        scanf("%*[^0-9]");
        scanf("%d,", &mae);
        scanf("%*[^0-9]");
        scanf("%d,", &pai);
        scanf("%*[^0-9]");
        scanf("%d", &filho);
        scanf("%*[^\n]");


            //printf("\nMAE((%d))\n", mae);
            //printf("FILHO((%d))\n", filho);
            //printf("PAI((%d))\n", pai);


        if(filho != -1){
            if(mae != -1){
                pessoas[filho].mae = (tPessoa *)malloc(sizeof(tPessoa));
                //pessoas[filho].mae = CriaPessoa();
                strcpy(pessoas[filho].mae->nome, pessoas[mae].nome);
                //printf("(MAE: %s\n)", pessoas[filho].mae->nome);
            }
            else{
                pessoas[filho].mae = NULL;
            }

            if(pai != -1){
                pessoas[filho].pai = (tPessoa *)malloc(sizeof(tPessoa));
                //pessoas[filho].pai = CriaPessoa();
                strcpy(pessoas[filho].pai->nome, pessoas[pai].nome);
                //printf("(PAI: %s\n)", pessoas[filho].pai->nome);
            }
            else{
                pessoas[filho].pai = NULL;
            }
            ImprimePessoa(&pessoas[filho]);

            if(mae != -1){
                free(pessoas[filho].mae);
                pessoas[filho].mae = NULL;
            }
            if(pai != -1){
                free(pessoas[filho].pai);
                pessoas[filho].pai = NULL;
            }
        }
    }
    
}

