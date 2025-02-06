#include <stdio.h>
#include <stdlib.h>
#include "operacao.h"
#include "conta.h"

typedef struct Operacao tOperacao;

struct Operacao{
    //tConta *conta;
    int idConta;
    float valor;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tOperacao. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero (exceto aquelas passadas como parâmetro para a função).
 *
 * @param conta - A conta que será associada a uma operação
 * @param valor - O valor da operação
 *
 * @return A variável do tipo tOperacao inicializada.
 */
tOperacao* CriaOperacao(tConta* conta, float valor){
    tOperacao *op = malloc(sizeof(struct Operacao));
    if(op == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    //op->conta = CriaConta(0);
    //op->conta = conta;
    op->idConta = RetornaIdConta(conta);
    op->valor = valor;
    return op;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma operacao.
 *
 * @param A variável do tipo tOperacao que será apagada.
 */
void DestroiOperacao(tOperacao* op){
    if(op != NULL){
        //DestroiConta(op->conta);
        free(op);
    }
}


/**
 * @brief Consulta o valor de uma operação especifica
 *
 * @param op - A operacao que queremos consultar o valor
 * @return O valor da operação cadastrada
 */
float ConsultaValorOperacao(tOperacao* op){
    return op->valor;
}


/**
 * @brief Imprime a operação. Ver formato nos exemplos de saída e/ou roteiro.
 *
 * @param op - A operacao que queremos imprimir
 */
void ImprimeOperacao(tOperacao* op){
    // Operação na conta 456 com valor 35431.00
    //printf("\nOperação na conta %d com valor %.2f", RetornaIdConta(op->conta), op->valor);
    printf("\nOperação na conta %d com valor %.2f", op->idConta, op->valor);
}

