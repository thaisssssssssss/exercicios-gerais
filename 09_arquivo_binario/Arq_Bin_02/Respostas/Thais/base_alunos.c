#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "base_alunos.h"

/**
 * @brief Estrutura para representar uma base de alunos.
 */
typedef struct BaseAlunos tBaseAlunos;

struct BaseAlunos{
    tAluno **alunos;
    int qtd;
};


/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos *base = malloc(sizeof(struct BaseAlunos));
    if(base == NULL) exit(EXIT_FAILURE);
    base->qtd = 0;

    return base;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    if(baseAlunos != NULL){
        if(baseAlunos->alunos != NULL){
            int i;
            for(i = 0; i < baseAlunos->qtd; i++) DestruirAluno(baseAlunos->alunos[i]);
            free(baseAlunos->alunos);
        }
        free(baseAlunos);
    }
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE *fp;
    fp = fopen(nomeArquivo,"rb");
    if(fp == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    fread(&baseAlunos->qtd, sizeof(int), 1, fp);
    baseAlunos->alunos = malloc(sizeof(struct Aluno*) * baseAlunos->qtd);
    if(baseAlunos->alunos == NULL) exit(EXIT_FAILURE);

    //printf("qtd alunos %d\n", baseAlunos->qtd);
    int i;
    for(i = 0; i < baseAlunos->qtd; i++){
        baseAlunos->alunos[i] = LeAluno(fp);
    }

    fclose(fp);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float media = 0;
    int i;
    for(i = 0; i < baseAlunos->qtd; i++){
        media += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return media / baseAlunos->qtd;
}

