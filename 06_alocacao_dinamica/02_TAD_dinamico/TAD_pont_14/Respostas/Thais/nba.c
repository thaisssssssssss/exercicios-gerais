#include <stdio.h>
#include "franquia.h"
#include "partida.h"
#include "nba.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria uma nova instância da NBA.
 * 
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA(){
    tNBA nba = malloc(sizeof(struct nba));
    if(nba == NULL){
        printf("Falha");
        exit(EXIT_FAILURE);
    }
    nba->qtdfranquias = 0;
    nba->maxfranquias = 30;
    nba->qtdpartidas = 0;
    nba->maxpartidas = 82;
    nba->listafranquias = malloc(nba->maxfranquias * sizeof(struct franquia));
    if(nba->listafranquias == NULL){
        printf("Falha");
        exit(EXIT_FAILURE);
    }
    nba->listapartidas = malloc(nba->maxpartidas * sizeof(struct franquia));
    if(nba->listapartidas == NULL){
        printf("Falha");
        exit(EXIT_FAILURE);
    }
    return nba;
}

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 * 
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba){
    char c;
    int f = 0, p = 0, i;
    while(1){
        scanf("%c", &c);
        if(c == ENCERRAR) break;
        else if(c == CAD_FRANQUIA){
            nba->listafranquias[f] = LeFranquia();
            f++;
        }
        else if(c == CAD_PARTIDA){
            nba->listapartidas[p] = LePartida();

            if(GetVencedorPartida(nba->listapartidas[p]) == TIME_CASA){
                for(i = 0; i < f; i++){
                    if(strcmp(GetTime1Partida(nba->listapartidas[p]), GetNomeFranquia(nba->listafranquias[i])) == 0){
                        AdicionaVitoriaCasaFranquia(nba->listafranquias[i]);
                        break;
                    }
                }
                for(i = 0; i < f; i++){
                    if(strcmp(GetTime2Partida(nba->listapartidas[p]), GetNomeFranquia(nba->listafranquias[i])) == 0){
                        AdicionaDerrotaForaFranquia(nba->listafranquias[i]);
                        break;
                    }
                }
            }
            else{
                for(i = 0; i < f; i++){
                    if(strcmp(GetTime2Partida(nba->listapartidas[p]), GetNomeFranquia(nba->listafranquias[i])) == 0){
                        AdicionaVitoriaForaFranquia(nba->listafranquias[i]);
                        break;
                    }
                }
                for(i = 0; i < f; i++){
                    if(strcmp(GetTime1Partida(nba->listapartidas[p]), GetNomeFranquia(nba->listafranquias[i])) == 0){
                        AdicionaDerrotaCasaFranquia(nba->listafranquias[i]);
                        break;
                    }
                }
            }
            p++;
        }
    }
    nba->qtdfranquias = f;
    nba->qtdpartidas = p;
}

/**
 * @brief Imprime o relatório final da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba){
    int i, vL = 0, dL = 0, vO = 0, dO = 0;
    float aL = 0, aO = 0;
    for(i = 0; i < nba->qtdfranquias; i++){
        ImprimeFranquia(nba->listafranquias[i]);
    }
    for(i = 0; i < nba->qtdfranquias; i++){
        if(strcmp(GetConferenciaFranquia(nba->listafranquias[i]), "LESTE") == 0){
            // LESTE 2 3 40.00
            vL += GetVitoriaCasaFranquia(nba->listafranquias[i]) + GetVitoriaForaFranquia(nba->listafranquias[i]);
            dL += GetDerrotaCasaFranquia(nba->listafranquias[i]) + GetDerrotaForaFranquia(nba->listafranquias[i]);
        }
        else if(strcmp(GetConferenciaFranquia(nba->listafranquias[i]), "OESTE") == 0){
            vO += GetVitoriaCasaFranquia(nba->listafranquias[i]) + GetVitoriaForaFranquia(nba->listafranquias[i]);
            dO += GetDerrotaCasaFranquia(nba->listafranquias[i]) + GetDerrotaForaFranquia(nba->listafranquias[i]);
        }
    }
    aL = vL + dL;
    if(aL != 0) aL = (float)(vL * 100) / aL;
    aO = vO + dO;
    if(aO != 0) aO = (float)(vO * 100) / aO;
    printf("LESTE %d %d %.2f\n", vL, dL, aL);
    printf("OESTE %d %d %.2f\n", vO, dO, aO);
}

/**
 * @brief Libera a memória alocada para a instância da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba){
    if(nba != NULL){
        int i;
        if(nba->listapartidas != NULL){
            for(i = 0; i < nba->qtdpartidas; i++){
                LiberaPartida(nba->listapartidas[i]);
            }
            free(nba->listapartidas);
        }
        if(nba->listafranquias != NULL){
            for(i = 0; i < nba->qtdfranquias; i++){
                LiberaFranquia(nba->listafranquias[i]);
            }
            free(nba->listafranquias);
        }
        free(nba);
    }
}

