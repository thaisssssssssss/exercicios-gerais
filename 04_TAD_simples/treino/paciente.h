#ifndef _PACIENTE_H_
#define _PACIENTE_H_

#define MAX_CARACTERES 100
#define MAX_LESOES 10
#define CARTAO_SUS 19

#include "data.h"
#include "lesao.h"

typedef struct{
    char nome[MAX_CARACTERES];
    tData dataNascimento;
    char cartaoSus[CARTAO_SUS];
    char genero;
    tLesao lesoes[MAX_LESOES];
    int numLesoes;
}   tPaciente;

tPaciente lePaciente();
void imprimePaciente(tPaciente paciente);
int ehMesmoCartaoSus(tPaciente paciente, char *cartaoSus);
tPaciente cadastraLesaoPaciente(tPaciente paciente, tLesao lesao);
int retornaIdadePaciente(tPaciente paciente);

#endif