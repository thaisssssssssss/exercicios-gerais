#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agencia.h"
//#include "vector.h"
//#include "conta.h"

/**
 * @brief Estrutura para representar uma agência bancária.
 */
typedef struct Agencia tAgencia;

struct Agencia{
    int num;
    char *nome;
    Vector *contas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia *a = malloc(sizeof(struct Agencia));
    if(a == NULL) exit(EXIT_FAILURE);

    a->contas = VectorConstruct();
    if(a->contas == NULL) exit(EXIT_FAILURE);
    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    if(agencia != NULL){
        if(((tAgencia*)agencia)->nome != NULL) free(((tAgencia*)agencia)->nome);
        VectorDestroy(((tAgencia*)agencia)->contas, DestroiConta);
        free(agencia);
    }
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    char nome[50];
    scanf("%d;%[^\n]%*c", &agencia->num, nome);
    //agencia->nome = malloc(strlen(nome) * sizeof(char) + 1);
    //strcpy(agencia->nome, nome);
    agencia->nome = strdup(nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    return (numAgencia == agencia2->num);
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia){
    float saldo = 0;
    int i, qtd = VectorSize(agencia->contas);

    for(i = 0; i < qtd; i++){
        saldo += GetSaldoConta(VectorGet(agencia->contas, i));
    }
    return saldo / (float)qtd;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    int qtd = VectorSize(agencia->contas);
    printf("    Nome: %s\n", agencia->nome);
	printf("    Numero: %d\n", agencia->num);
    printf("    Numero de contas cadastradas: %d\n", qtd);
	printf("    Saldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}
