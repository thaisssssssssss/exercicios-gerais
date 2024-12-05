#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "data.h"

tData leData(){
    tData data;
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);
    data = criaData(dia, mes, ano);
    return data;    
}

tData criaData(int dia, int mes, int ano){
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    data.idade = calculaIdadePaciente(dia, mes, ano);
    return data;
}

int calculaIdadePaciente(int dia, int mes, int ano){
    int idade;

    if(9 > mes) idade = 2023 - ano;
    else if(9 < mes) idade = 2023 - ano - 1;
    else{
        if(12 >= dia) idade = 2023 - ano;
        else idade = 2023 - ano - 1;
    }

    return idade;
}