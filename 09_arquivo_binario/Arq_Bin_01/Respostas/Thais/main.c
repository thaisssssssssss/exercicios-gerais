#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(){
    int qtdAlunos;
    scanf("%d", &qtdAlunos);
    Aluno **alunos = CriaVetorAlunos(qtdAlunos);
    LeAlunos(alunos, qtdAlunos);
    ImprimeAlunos(alunos, qtdAlunos);
    return 0;
}