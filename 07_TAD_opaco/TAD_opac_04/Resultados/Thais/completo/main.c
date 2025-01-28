#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>

int main(){
    int qtdAlunos, i, j;
    scanf("%d", &qtdAlunos);
    tAluno *alunos[qtdAlunos];
    for(i = 0; i < qtdAlunos; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }
    tAluno *aux;
    for(i = 0; i < qtdAlunos; i++){
        for(j = i; j < qtdAlunos; j++){
            if(ComparaMatricula(alunos[i], alunos[j]) == 1){
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
}