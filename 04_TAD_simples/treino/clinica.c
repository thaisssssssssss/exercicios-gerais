#include "data.h"
#include "lesao.h"
#include "paciente.h"
#include "clinica.h"
#include <stdio.h>


tClinica abreClinica(){
    tClinica clinica;
    clinica.totalPacientes = 0;
    clinica.mediaIdade = 0;
    clinica.totalLesoes = 0;
    clinica.totalCirurgias = 0;
    return clinica;
}   

tClinica atendePacientes(tClinica clinica){
    char idCadastro;
    int numPacientes = 0, i;

    while(1){
        scanf("%c", &idCadastro);
        if(idCadastro == 'F'){
            break;
        }
        else if(idCadastro == 'P'){
            clinica.pacientes[clinica.totalPacientes] = lePaciente();
            clinica.mediaIdade += retornaIdadePaciente(clinica.pacientes[clinica.totalPacientes]);
            clinica.totalPacientes++;
        }
        else if(idCadastro == 'L'){
            char cartaoSus[CARTAO_SUS];
            scanf("%*[^0-9]");
            scanf("%[^\n]", cartaoSus);
            tLesao lesao;
            lesao = leLesao();

            for(i = 0; i < clinica.totalPacientes; i++){
                if(ehMesmoCartaoSus(clinica.pacientes[i], cartaoSus)){
                    clinica.pacientes[i] = cadastraLesaoPaciente(clinica.pacientes[i], lesao);
                    if(ehNecessariaCirurgia(lesao)) clinica.totalCirurgias++;
                    clinica.totalLesoes++;
                }
            }
        }
    }
    clinica.mediaIdade = clinica.mediaIdade / clinica.totalPacientes;
    return clinica;
}

void imprimeDadosClinica(tClinica clinica){
    int i;
    printf("TOTAL PACIENTES: %d\n", clinica.totalPacientes);
    printf("MEDIA IDADE (ANOS): %d\n", clinica.mediaIdade);
    printf("TOTAL LESOES: %d\n", clinica.totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n", clinica.totalCirurgias);
    printf("LISTA DE PACIENTES");
    for(i = 0; i < clinica.totalPacientes; i++){
        imprimePaciente(clinica.pacientes[i]);
    }
}
