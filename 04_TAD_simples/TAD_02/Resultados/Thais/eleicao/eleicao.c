#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao(){
    tEleicao eleicao;
    eleicao.totalPresidentes = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;

    eleicao.totalGovernadores = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    eleicao.totalEleitores = 0;

    int qtdCandidatos, i;
    scanf("%d", &qtdCandidatos);

    for(i = 0; i < qtdCandidatos; i++){
        tCandidato candidato;
        char cargo;
        candidato = LeCandidato();
        cargo = ObtemCargo(candidato);

        if(cargo == 'P'){
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
            //acabar o processo se passar de tres
        }
        else if(cargo == 'G'){
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
    }

    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao){
    scanf("%d", &eleicao.totalEleitores);
    if(eleicao.totalEleitores > 10){
        printf("ELEICAO ANULADA");
        exit(0);
    }

    int i, j, votoP, votoG, p, g, votoValido = 0, nulo = 0, eleitorRepetido = 0;

    for(i = 0; i < eleicao.totalEleitores; i++){
        eleicao.eleitores[i] = LeEleitor();
    }

    for(i = 0; i < eleicao.totalEleitores; i++){
        for(j = i + 1; j < eleicao.totalEleitores; j++){
            if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])){
                printf("ELEICAO ANULADA");
                exit(0);
            }
        }
    }


    for(i = 0; i < eleicao.totalEleitores; i++){
        votoP = ObtemVotoPresidente(eleicao.eleitores[i]);
        if(votoP == 0){
            eleicao.votosBrancosPresidente++;
        }
        else{
            for(p = 0; p < eleicao.totalPresidentes; p++){
                votoValido = VerificaIdCandidato(eleicao.presidentes[p], votoP);
                if(votoValido){
                    eleicao.presidentes[p] = IncrementaVotoCandidato(eleicao.presidentes[p]);
                    nulo = 1;
                }
            }
            if(nulo == 0){
                eleicao.votosNulosPresidente++;
            }
        }

        nulo = 0;

        votoG = ObtemVotoGovernador(eleicao.eleitores[i]);
        if(votoG == 0){
            eleicao.votosBrancosGovernador++;
        }
        else{
            for(g = 0; g < eleicao.totalGovernadores; g++){
                votoValido = VerificaIdCandidato(eleicao.governadores[g], votoG);
                if(votoValido){
                    eleicao.governadores[g] = IncrementaVotoCandidato(eleicao.governadores[g]);
                    nulo = 1;
                }
            }
            if(nulo == 0){
                eleicao.votosNulosGovernador++;
            }
        }

        nulo = 0;
    }
    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao){
    int p, g, votosAtualMaior, votos;
    tCandidato presidente = eleicao.presidentes[0];
    tCandidato empateP;
    tCandidato governador = eleicao.governadores[0];
    tCandidato empateG;

    empateP.votos = 0;
    empateG.votos = 0;
    for(p = 1; p < eleicao.totalPresidentes; p++){
        votosAtualMaior = ObtemVotos(presidente);
        votos = ObtemVotos(eleicao.presidentes[p]);
        if(votos > votosAtualMaior){
            presidente = eleicao.presidentes[p];
        }
        else if(votos == votosAtualMaior){
            if(!(EhMesmoCandidato(presidente, eleicao.presidentes[p]))){
                empateP = eleicao.presidentes[p];
            }
        }
    }
               
    for(g = 1; g < eleicao.totalPresidentes; g++){
        votosAtualMaior = ObtemVotos(governador);
        votos = ObtemVotos(eleicao.governadores[g]);
        if(votos > votosAtualMaior){
            governador = eleicao.governadores[g];
        }
        else if(votos == votosAtualMaior){
            if(!(EhMesmoCandidato(governador, eleicao.governadores[g]))){
                empateG = eleicao.governadores[g];
            }
        }
    }
    
    float percentualVotos = 0;

    printf("- PRESIDENTE ELEITO: ");
    if(presidente.votos == empateP.votos){
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else{
        if(ObtemVotos(presidente) < (eleicao.votosNulosPresidente + eleicao.votosBrancosPresidente)){
            printf("SEM DECISAO\n");
        }
        else{
            percentualVotos = CalculaPercentualVotos(presidente, eleicao.totalEleitores);
            ImprimeCandidato (presidente, percentualVotos);
        }
    }

    printf("- GOVERNADOR ELEITO: ");
    if(governador.votos == empateG.votos){
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else{
        if(ObtemVotos(governador) < (eleicao.votosNulosGovernador + eleicao.votosBrancosGovernador)){
            printf("SEM DECISAO\n");
        }
        else{
            percentualVotos = CalculaPercentualVotos(governador, eleicao.totalEleitores);
            ImprimeCandidato (governador, percentualVotos);
        }
    }

    printf("- NULOS E BRANCOS: %d, %d", eleicao.votosNulosGovernador + eleicao.votosNulosPresidente, eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente);
}

