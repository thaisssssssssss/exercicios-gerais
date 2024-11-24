#include "vendedor.h"
#include <stdio.h>
#include <string.h>

tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao){
    tVendedor vendedor;
    strcpy(vendedor.nome, nome);
    vendedor.valor_vendido = 0;
    vendedor.salario = salario;
    vendedor.prct_comissao = prct_comissao;
    return vendedor;
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[50]){
    return (strcmp(vendedor.nome, nome) == 0);
}

tVendedor ContabilizaVenda(tVendedor vendedor, float valor){
    vendedor.valor_vendido += valor;
    return vendedor;
}

float GetSalario(tVendedor vendedor){
    return vendedor.salario;
}

float GetComissao(tVendedor vendedor){
    float comissao;
    float totalVendido = GetTotalVendido(vendedor);
    comissao = vendedor.prct_comissao * totalVendido;
    return comissao;
}

float GetTotalVendido(tVendedor vendedor){
    return vendedor.valor_vendido;
}

float GetTotalRecebido(tVendedor vendedor){
    float salario = GetSalario(vendedor);
    float comissao = GetComissao(vendedor);
    float total = salario + comissao;
    return total;
}

void ImprimeRelatorioVendedor(tVendedor vendedor){
    printf("%s > Total vendido: R$%.2f\n    Total recebido: R$%.2f\n", vendedor.nome, GetTotalVendido(vendedor), GetTotalRecebido(vendedor));
}

