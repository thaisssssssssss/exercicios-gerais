#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "data.h"

tPaciente lePaciente(){
    tPaciente paciente;
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", paciente.nome);
    paciente.dataNascimento = leData();
    scanf("%*[^0-9]");
    scanf("%[^\n]", paciente.cartaoSus);
    scanf("%*[^FMO]");
    scanf("%c", &paciente.genero);
    paciente.numLesoes = 0;
    return paciente;
}

void imprimePaciente(tPaciente paciente){
    int i;
    if(paciente.numLesoes != 0){
        printf("\n- %s -", paciente.nome);
        for(i = 0; i < paciente.numLesoes; i++){
            imprimeLesao(paciente.lesoes[i]);
        }
    }
    //printf("%s\n", paciente.cartaoSus);
    //printf("%c\n", paciente.genero);
    //printf("%d\n", paciente.dataNascimento.idade);
}

int ehMesmoCartaoSus(tPaciente paciente, char *cartaoSus){
    return (strcmp(paciente.cartaoSus, cartaoSus) == 0);
}

tPaciente cadastraLesaoPaciente(tPaciente paciente, tLesao lesao){
    paciente.lesoes[paciente.numLesoes] = lesao;
    paciente.numLesoes++;
    return paciente;
}

int retornaIdadePaciente(tPaciente paciente){
    return paciente.dataNascimento.idade;
}
