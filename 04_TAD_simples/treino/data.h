#ifndef _DATA_H_
#define _DATA_H_

typedef struct{
    int dia;
    int mes;
    int ano;
    int idade;
}   tData;

tData leData();
tData criaData(int dia, int mes, int ano);
int calculaIdadePaciente(int dia, int mes, int ano);

#endif