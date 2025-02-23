#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

/**
 * @brief Estrutura para representar uma conta bancária.
 */
typedef struct Conta tConta;

struct Conta{
    int num;
    char *nome;
    float saldo;
};

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta(){
    tConta *c = malloc(sizeof(struct Conta));
    if(c == NULL) exit(EXIT_FAILURE);

    c->num = 0;
    c->saldo = 0;
    return c;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta){
    //free(*conta->nome);
    if(conta != NULL){
        if(((tConta*)conta)->nome != NULL){
            free(((tConta*)conta)->nome);
        }
        free(conta);
    }

}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta){
    char nome[50];
    scanf("%d;%[^;];%f", &conta->num, nome, &conta->saldo);
    conta->nome = malloc(strlen(nome) * sizeof(char) + 1);
    strcpy(conta->nome, nome);
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta){
    return conta->saldo;
}

