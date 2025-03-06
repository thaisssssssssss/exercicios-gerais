#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct aluno Aluno;

struct aluno{
    char *nome;
    char *dataNasc;
    char *curso;
    char *periodoIngresso;
    int percConclusao;
    float CRA;
};

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno **alunos = malloc(sizeof(struct aluno*) * numeroAlunos);
    if(alunos == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *aluno = malloc(sizeof(struct aluno));
    if(aluno == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    aluno->nome = strdup(nome);
    aluno->dataNasc = strdup(dtNasc);
    aluno->curso = strdup(cursoUfes);
    aluno->periodoIngresso = strdup(periodoIngresso);
    aluno->percConclusao = percConclusao;
    aluno->CRA = CRA;   

    return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    int i;

    for(i = 0; i < numeroAlunos; i++){

        char nome[100];
        char dataNasc[100];
        char curso[100];
        char periodoIngresso[100];
        int percConclusao;
        float CRA;

        scanf("%*[^A-Z^a-z]");
        scanf("%[^\n]", nome);
        scanf("%*[^0-9]");
        scanf("%[^\n]", dataNasc);
        scanf("%*[^A-Z^a-z]");
        scanf("%[^\n]", curso);
        scanf("%*[^0-9]");
        scanf("%[^\n]", periodoIngresso);
        scanf("%*[^0-9]");
        scanf("%d", &percConclusao);
        scanf("%*[^0-9]");
        scanf("%f", &CRA);

        vetorAlunos[i] = CriaAluno(nome, dataNasc, curso, periodoIngresso, percConclusao, CRA);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    if(alunos != NULL){
        int i;
        for(i = 0; i < numeroAlunos; i++){
            if(alunos[i] != NULL){
                if(alunos[i]->nome != NULL) free(alunos[i]->nome);
                if(alunos[i]->dataNasc != NULL) free(alunos[i]->dataNasc);
                if(alunos[i]->curso != NULL) free(alunos[i]->curso);
                if(alunos[i]->periodoIngresso != NULL) free(alunos[i]->periodoIngresso);
            }
            free(alunos[i]);
        }
        free(alunos);
    }

}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos);

void CarregaAlunosBinario(Aluno **alunos, char *fileName);

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    int i;
        for(i = 0; i < numeroAlunos; i++){
            printf("Aluno %d:\n", i);
            printf("Nome: %s\n", alunos[i]->nome);
            printf("Data Nascimento: %s\n", alunos[i]->dataNasc);
            printf("Curso: %s\n", alunos[i]->curso);
            printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
            printf("%% Conclusao do Curso: %d\n", alunos[i]->percConclusao);
            printf("CRA: %.2f\n", alunos[i]->CRA);
        }



// Aluno 0:
// Nome: Seraphina Luminara
// Data Nascimento: 12 de julho de 2995
// Curso: Engenharia Quantica
// Periodo Ingresso: 2023/1
// % Conclusao do Curso: 85
// CRA: 8.70
}

