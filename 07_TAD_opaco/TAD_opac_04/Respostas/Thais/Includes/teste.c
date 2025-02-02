#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct Aluno {
    char *nome;
    int matricula;
    int n1, n2, n3;
};

tAluno* CriaAluno() {
    tAluno* aluno = (tAluno*)malloc(sizeof(tAluno));
    if (aluno == NULL) {
        fprintf(stderr, "Erro ao alocar memória para aluno.\n");
        exit(EXIT_FAILURE);
    }
    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    return aluno;
}

void ApagaAluno(tAluno *aluno) {
    if (aluno != NULL) {
        free(aluno->nome);
        free(aluno);
    }
}

void LeAluno(tAluno *aluno) {
    int tamanho = 0;
    char ch;
    scanf("%*[^A-Z^a-z]");
    aluno->nome = malloc(sizeof(char));
    if (aluno->nome == NULL) {
        fprintf(stderr, "Erro ao alocar memória para nome do aluno.\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = getchar()) != '\n' && ch != EOF) {
        aluno->nome = realloc(aluno->nome, (tamanho + 2) * sizeof(char));
        if (aluno->nome == NULL) {
            fprintf(stderr, "Erro ao realocar memória para nome do aluno.\n");
            exit(EXIT_FAILURE);
        }
        aluno->nome[tamanho] = ch;
        tamanho++;
    }
    aluno->nome[tamanho] = '\0';

    scanf("%d", &aluno->matricula);
    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2) {
    if (aluno1->matricula > aluno2->matricula) return 1;
    else if (aluno1->matricula < aluno2->matricula) return -1;
    else return 0;
}

int CalculaMediaAluno(tAluno* aluno) {
    int media = aluno->n1 + aluno->n2 + aluno->n3;
    return media / 3;
}

int VerificaAprovacao(tAluno* aluno) {
    int media = CalculaMediaAluno(aluno);
    return media >= 7 ? 1 : 0;
}

void ImprimeAluno(tAluno* aluno) {
    printf("%s\n", aluno->nome);
}
