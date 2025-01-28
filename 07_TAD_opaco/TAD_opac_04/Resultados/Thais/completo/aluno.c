#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>



/** char *LeVetor(char *vetor, int *tamanho) {
     int length = 0, ch;
     while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length == *tamanho - 1) { // -1 para o '\0'
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }
        vetor[length] = ch;
        length++;
    }
    //vetor[length] = '\0';
    return vetor;
}
* */ 





struct Aluno{
    char *nome;
    int matricula;
    int n1, n2, n3;
};

/**
 * @brief Cria um novo aluno vazio. Os atributos inteiros devem receber valor -1, e o ponteiro do nome deve apontar para NULL;
 * 
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno* CriaAluno(){
    tAluno* aluno = (tAluno*)malloc(sizeof(tAluno));
    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    return aluno;
} 

/**
 * @brief Função para liberar toda a memória alocada dinamicamente para estrututas do tipo tAluno
 * 
 * @param aluno Ponteiro para estrutura do tipo tAluno a ser apagada.
 */
void ApagaAluno(tAluno *aluno){
    if(aluno != NULL){
        free(aluno->nome);
        free(aluno);
        aluno->nome = NULL;
        aluno = NULL;
    }
}


/**
 * @brief Lê os dados de um aluno.
 * 
 * @param Ponteiro para aluno (alocado dinamicamente), cujos dados serão preenchidos nessa função
 */
void LeAluno(tAluno *aluno){
    int tamanho = 0;
    char ch;
    scanf("%*[^A-Z^a-z]");
    aluno->nome = malloc(sizeof(char));
    while ((ch = getchar()) != '\n' && ch != EOF) {
        aluno->nome = realloc(aluno->nome, (tamanho + 1) * sizeof(char));
        aluno->nome[tamanho] = '\0';
        aluno->nome[tamanho] = ch;
        tamanho++;
    }

    scanf("%d", &aluno->matricula);
    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
}

/**
 * @brief Compara as matrículas de dois alunos.
 * 
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado.
 * @param aluno2 Ponteiro para o segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula) return 1;
    else if(aluno1->matricula < aluno2->matricula) return -1;
    else return 0;
}

/**
 * @brief Calcula a média das notas de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ter a média calculada.
 * @return int Retorna a média das notas do aluno.
 */
int CalculaMediaAluno(tAluno* aluno){
    int media = 0;
    media = aluno->n1 + aluno->n2 + aluno->n3;
    media = media / 3;
    //printf("(%d) %s\n", media, aluno->nome);
    return media;
}

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 * 
 * @param aluno Ponteiro para aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno* aluno){
    int media = CalculaMediaAluno(aluno);
    if(media >= 7) return 1;
    else return 0;
}

/**
 * @brief Imprime os dados de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ser impresso.
 */
void ImprimeAluno(tAluno* aluno){
    if(VerificaAprovacao(aluno)) printf("%s\n", aluno->nome);
}
