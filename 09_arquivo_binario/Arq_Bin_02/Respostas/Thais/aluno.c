#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

/**
 * @brief Estrutura para representar um aluno.
 */
typedef struct Aluno tAluno;

struct Aluno{
    char *nome;
    char *data;
    char *curso;
    int perido;
    float CR;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno *aluno = malloc(sizeof(struct Aluno));
    if(aluno == NULL) exit(EXIT_FAILURE);

    aluno->nome = strdup(nome);
    aluno->data = strdup(dataNascimento);
    aluno->curso = strdup(curso);
    aluno->perido = periodo;
    aluno->CR = coeficienteRendimento;

    return aluno;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){
    if(aluno != NULL){
        if(aluno->nome != NULL) free(aluno->nome);
        if(aluno->data != NULL) free(aluno->data);
        if(aluno->curso != NULL) free(aluno->curso);
        free(aluno);
    }
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){
    FILE *fp = arquivo_binario;
    //fp = fopen(arquivo_binario,"rb");
    if(fp == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    char nome[101];
    char data[12];
    char curso[51];
    int periodo;
    float cr;

    fread(nome, sizeof(char), 100, fp);
    nome[100] = '\0';
    //printf("%s\n", nome);

    fread(data, sizeof(char), 11, fp);
    data[11] = '\0';
    //printf("%s\n", data);

    fread(curso, sizeof(char), 50, fp);
    curso[50] = '\0';
    //printf("%s\n", curso);

    fread(&periodo, sizeof(int), 1, fp);
    //printf("%d\n", periodo);

    fread(&cr, sizeof(float), 1, fp);
    //printf("%.2f\n", cr);

    //fclose(fp);

    tAluno *aluno = CriarAluno(nome, data, curso, periodo, cr);
    return aluno;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->CR;
}
