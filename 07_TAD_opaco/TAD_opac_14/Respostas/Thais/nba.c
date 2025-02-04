#include "franquia.h"
#include "partida.h"
#include "nba.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nba{
    tFranquia *franquias;
    tPartida *partidas;
    int qtdFranquias;
    int qtdPartidas;
};

/**
 * @brief Cria uma nova instância da NBA.
 * 
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA(){
    tNBA nba = malloc(sizeof(tNBA));
    if(nba == NULL) exit(EXIT_FAILURE);
    nba->franquias = malloc(MAX_FR * sizeof(tFranquia*));
    if(nba->franquias == NULL) exit(EXIT_FAILURE);
    nba->partidas = malloc(MAX_PT * sizeof(tPartida*));
    if(nba->partidas == NULL) exit(EXIT_FAILURE);
    return nba;
}

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 * 
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba){
    char instancia;
    int f = 0, p = 0, i, vencedor;;
    while(1){
        scanf("%c", &instancia);
        if(instancia == ENCERRAR) break;
        else if(instancia == CAD_FRANQUIA){
                nba->franquias[f] = LeFranquia();
                f++;
        }
        else if(instancia == CAD_PARTIDA){
                nba->partidas[p] = LePartida();

                vencedor = GetVencedorPartida(nba->partidas[p]);
                if(vencedor == TIME_CASA){
                    for(i = 0; i < f; i++){
                        if(strcmp(GetTime1Partida(nba->partidas[p]), GetNomeFranquia(nba->franquias[i])) == 0){
                            AdicionaVitoriaCasaFranquia(nba->franquias[i]);
                            break;
                        }
                    }
                    for(i = 0; i < f; i++){
                        if(strcmp(GetTime2Partida(nba->partidas[p]), GetNomeFranquia(nba->franquias[i])) == 0){
                            AdicionaDerrotaForaFranquia(nba->franquias[i]);
                            break;
                        }
                    }
                }
                else if(vencedor == TIME_FORA){
                    for(i = 0; i < f; i++){
                        if(strcmp(GetTime2Partida(nba->partidas[p]), GetNomeFranquia(nba->franquias[i])) == 0){
                            AdicionaVitoriaForaFranquia(nba->franquias[i]);
                            break;
                        }
                    }
                    for(i = 0; i < f; i++){
                        if(strcmp(GetTime1Partida(nba->partidas[p]), GetNomeFranquia(nba->franquias[i])) == 0){
                            AdicionaDerrotaCasaFranquia(nba->franquias[i]);
                            break;
                        }
                    }
                }
                p++;
        }
    }
    nba->qtdFranquias = f;
    nba->qtdPartidas = p;
    return nba;
}

/**
 * @brief Imprime o relatório final da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba){
    int i, vL = 0, vO = 0, dL = 0, dO = 0;
    float aL = 0, aO = 0;
    for(i = 0; i < nba->qtdFranquias; i++){
        ImprimeFranquia(nba->franquias[i]);
        if(strcmp(GetConferenciaFranquia(nba->franquias[i]), "LESTE") == 0){
            vL += GetVitoriaCasaFranquia(nba->franquias[i]) + GetVitoriaForaFranquia(nba->franquias[i]);
            dL += GetDerrotaCasaFranquia(nba->franquias[i]) + GetDerrotaForaFranquia(nba->franquias[i]);
        }
        else if(strcmp(GetConferenciaFranquia(nba->franquias[i]), "OESTE") == 0){
            vO += GetVitoriaCasaFranquia(nba->franquias[i]) + GetVitoriaForaFranquia(nba->franquias[i]);
            dO += GetDerrotaCasaFranquia(nba->franquias[i]) + GetDerrotaForaFranquia(nba->franquias[i]);
        }
    }
    aL = vL + dL;
    if(aL != 0) aL = (vL * 100) / aL;
    aO = vO + dO;
    if(aO != 0) aO = (vO * 100) / aO;
    printf("LESTE %d %d %.2f\n", vL, dL, aL);
    printf("OESTE %d %d %.2f\n", vO, dO, aO);
}

/**
 * @brief Libera a memória alocada para a instância da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba){
    int i;
    if(nba != NULL){
        if(nba->franquias != NULL){
            for(i = 0; i < nba->qtdFranquias; i++){
                LiberaFranquia(nba->franquias[i]);
            }
        }
        if(nba->partidas != NULL){
            for(i = 0; i < nba->qtdPartidas; i++){
                LiberaPartida(nba->partidas[i]);
            }
        }
        free(nba);
    }
}
