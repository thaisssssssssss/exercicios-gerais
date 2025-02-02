#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"



#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

typedef struct {
    tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
    int totalPresidentes;

    tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor eleitores[MAX_ELEITORES];
    int totalEleitores;
    
} tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao(){
    tEleicao e;
    int i, qtdCand;
    e.totalPresidentes = 0;
    e.totalGovernadores = 0;
    e.totalEleitores = 0;

    e.votosBrancosPresidente = 0;
    e.votosBrancosGovernador = 0;

    e.votosNulosPresidente = 0;
    e.votosNulosGovernador = 0;

    scanf("%d", &qtdCand);
    if(qtdCand > MAX_CANDIDATOS_POR_CARGO){
        printf("ELEICAO ANULADA\n");
        assert(0 == 1);
    }
    tCandidato c[qtdCand];
    char cargo; 

    for(i = 0; i < qtdCand; i++){
        c[i] = LeCandidato();
        (ObtemCargo(c[i]) == 'P') ? e.totalPresidentes++ : e.totalGovernadores++;
    }

    return e;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao);

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao);
