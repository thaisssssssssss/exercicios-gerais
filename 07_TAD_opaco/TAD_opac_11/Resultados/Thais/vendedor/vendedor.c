#include <stdio.h>
#include <stdlib.h>
#include "vendedor.h"
#include <string.h>

struct Vendedor{
    char *nome;
    float salario;
    float prct_comissao;
    float valor_vendido;
};

/**
 * @brief Registra um novo vendedor.
 * 
 * @param nome Nome do vendedor.
 * @param salario Salário base do vendedor.
 * @param prct_comissao Porcentagem de comissão do vendedor.
 * @return tVendedor Retorna a estrutura do tipo tVendedor com os dados do vendedor registrado.
 */
tVendedor* RegistraVendedor(char* nome, float salario, float prct_comissao){
    tVendedor *v = malloc(sizeof(tVendedor));
    v->nome = malloc(strlen(nome) * sizeof(char) + 1);
    strcpy(v->nome, nome);
    v->salario = salario;
    v->prct_comissao = prct_comissao;
    v->valor_vendido = 0;
    return v;
}

/**
 * @brief Libera a memória alocada para um vendedor.
 * 
 * @param vendedor Ponteiro para o vendedor a ser apagado.
 */
void ApagaVendedor(tVendedor* vendedor){
    if(vendedor != NULL){
        if(vendedor->nome != NULL){
            free(vendedor->nome);
        }
        free(vendedor);
    }
}

/**
 * @brief Verifica se o nome de um vendedor é igual a outro.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser verificado.
 * @param nome Nome do vendedor a ser comparado.
 * @return int Retorna 1 se o nome do vendedor é igual ao nome passado como parâmetro, ou 0 caso contrário.
 */
int VerificaNomeVendedor(tVendedor* vendedor, char* nome){
    return (strcmp(vendedor->nome, nome) == 0);
}

/**
 * @brief Contabiliza uma venda para um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor (será alterada)
 * @param valor Valor da venda a ser contabilizada.
 */
void ContabilizaVenda(tVendedor* vendedor, float valor){
    vendedor->valor_vendido += valor;
}

/**
 * @brief Obtém o salário de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o salário do vendedor.
 */
float GetSalario(tVendedor* vendedor){
    return vendedor->salario;
}

/**
 * @brief Obtém a comissão de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna a comissão do vendedor.
 */
float GetComissao(tVendedor* vendedor){
    float c;
    c = vendedor->prct_comissao * GetTotalVendido(vendedor);
    return c;
}

/**
 * @brief Obtém o total vendido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total vendido pelo vendedor.
 */
float GetTotalVendido(tVendedor* vendedor){
    return vendedor->valor_vendido;
}

/**
 * @brief Obtém o total recebido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total recebido pelo vendedor (salário + comissão).
 */
float GetTotalRecebido(tVendedor* vendedor){
    float t;
    t = GetSalario(vendedor) + GetComissao(vendedor);
    return t;
}

/**
 * @brief Imprime o relatório de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 */
void ImprimeRelatorioVendedor(tVendedor* vendedor){
    printf("    %s > Total vendido: R$%.2f\n", vendedor->nome, GetTotalVendido(vendedor));
    printf("        Total recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}

