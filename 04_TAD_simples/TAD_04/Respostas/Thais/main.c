#include "aluno.h"
#include <stdio.h>
#include <string.h>

int main(){
    int qtdAlunos, i, j;
    scanf("%d", &qtdAlunos);
    tAluno alunos[qtdAlunos];
    tAluno aux;

    for(i = 0; i < qtdAlunos; i++){
        alunos[i] = LeAluno();
    }

    for(i = 0; i < qtdAlunos; i++){
        for(j = i; j < qtdAlunos; j++){
            if(ComparaMatricula(alunos[i], alunos[j]) == 1){
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }

    int aprovado = 0;
    
    for(i = 0; i < qtdAlunos; i++){
        aprovado = VerificaAprovacao(alunos[i]);
        if(aprovado) ImprimeAluno(alunos[i]);
    }

    return 0;
}