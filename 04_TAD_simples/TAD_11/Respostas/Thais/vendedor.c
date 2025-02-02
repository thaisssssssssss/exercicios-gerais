#include <stdio.h>
#include <string.h>
#include "vendedor.h"

/**
 * @brief Registra um novo vendedor.
 * 
 * @param nome Nome do vendedor.
 * @param salario Salário base do vendedor.
 * @param prct_comissao Porcentagem de comissão do vendedor.
 * @return tVendedor Retorna a estrutura do tipo tVendedor com os dados do vendedor registrado.
 */
tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao){
    tVendedor v;
    strcpy(v.nome, nome);
    v.salario = salario;
    v.prct_comissao = prct_comissao;
    v.valor_vendido = 0;
    return v;
}

/**
 * @brief Verifica se o nome de um vendedor é igual a outro.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser verificado.
 * @param nome Nome do vendedor a ser comparado.
 * @return int Retorna 1 se o nome do vendedor é igual ao nome passado como parâmetro, ou 0 caso contrário.
 */
int VerificaNomeVendedor(tVendedor vendedor, char nome[50]){
    if(strcmp(vendedor.nome, nome) == 0) return 1;
    else return 0;
}

/**
 * @brief Contabiliza uma venda para um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @param valor Valor da venda a ser contabilizada.
 * @return tVendedor Retorna a estrutura do tipo tVendedor atualizada com o valor da venda contabilizada.
 */
tVendedor ContabilizaVenda(tVendedor vendedor, float valor){
    vendedor.valor_vendido = vendedor.valor_vendido + valor;
    return vendedor;
}

/**
 * @brief Obtém o salário de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o salário do vendedor.
 */
float GetSalario(tVendedor vendedor){
    return vendedor.salario;
}

/**
 * @brief Obtém a comissão de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna a comissão do vendedor.
 */
float GetComissao(tVendedor vendedor){
    float pct = 0;
    pct = vendedor.prct_comissao * GetTotalVendido(vendedor);
    return pct;
}

/**
 * @brief Obtém o total vendido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total vendido pelo vendedor.
 */
float GetTotalVendido(tVendedor vendedor){
    return vendedor.valor_vendido;
}

/**
 * @brief Obtém o total recebido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total recebido pelo vendedor (salário + comissão).
 */
float GetTotalRecebido(tVendedor vendedor){
    float total = 0;
    total = GetComissao(vendedor) + GetSalario(vendedor);
    return total;
}

/**
 * @brief Imprime o relatório de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 */
void ImprimeRelatorioVendedor(tVendedor vendedor){
    printf("    %s > Total vendido: R$%.2f\n", vendedor.nome, GetTotalVendido(vendedor));
    printf("        Total recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}
