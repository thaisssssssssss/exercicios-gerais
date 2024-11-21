#include "candidato.h"
#include <stdio.h>
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;
    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;
    
    return candidato;
}

tCandidato LeCandidato(){
    tCandidato candidato;
    char nome[50];
    char partido[50];
    char cargo;
    int id;
    
    scanf("%[^,],", nome);
    scanf("%[^,],", partido);
    scanf("%c,", &cargo);
    scanf("%d", &id);

    candidato = CriaCandidato(nome, partido, cargo, id);

    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id){
    return (candidato.id == id);
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    int iguais = 0;

    if(strcmp(candidato1.nome, candidato2.nome) == 0){
        iguais++;
    }
    if(strcmp(candidato1.partido, candidato2.partido) == 0){
        iguais++;
    }
    if(candidato1.cargo == candidato2.cargo){
        iguais++;
    }
    if(candidato1.id == candidato2.id){
        iguais++;
    }

    return (iguais == 4);
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos = candidato.votos + 1;
    return candidato;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    float percentual = 0;
    percentual = ((float(candidato.votos * 100)) / float(totalVotos));

    return percentual;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s ", candidato.nome);
    printf("(%s), ", candidato.partido);
    printf("%d voto(s), %.2f", candidato.votos, percentualVotos);
    printf("%");
    printf("\n");
}
