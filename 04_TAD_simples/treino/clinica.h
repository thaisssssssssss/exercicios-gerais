#ifndef _CLINICA_H_
#define _CLINICA_H_

#include "data.h"
#include "lesao.h"
#include "paciente.h"

typedef struct{
    int totalPacientes;
    int mediaIdade;
    int totalLesoes;
    int totalCirurgias;
    tPaciente pacientes[MAX_CARACTERES];
}   tClinica;


tClinica abreClinica();
tClinica atendePacientes(tClinica clinica);
void imprimeDadosClinica(tClinica clinica);

#endif