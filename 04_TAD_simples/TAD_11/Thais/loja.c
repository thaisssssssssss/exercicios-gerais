#include "vendedor.h"
#include "loja.h"
#include <stdio.h>
#include <string.h>

tLoja AbreLoja(int id, float aluguel){
    tLoja loja;
    loja.id = id;
    loja.aluguel = aluguel;
    loja.totalVendedores = 0;
    loja.lucro = 0;

    return loja;
}

int VerificaIdLoja(tLoja loja, int id){
    return (loja.id == id);
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor){
    if(loja.totalVendedores < 9){
        strcpy(loja.vendedores[loja.totalVendedores].nome, vendedor.nome);
        loja.vendedores[loja.totalVendedores].valor_vendido = vendedor.valor_vendido;
        loja.vendedores[loja.totalVendedores].salario = vendedor.salario;
        loja.vendedores[loja.totalVendedores].prct_comissao = vendedor.prct_comissao;
        loja.totalVendedores++;
    }
    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor){
    int i, ehVendedor = 0;
    for(i = 0; i < loja.totalVendedores; i++){
        ehVendedor = VerificaNomeVendedor(loja.vendedores[i], nome);
        if(ehVendedor == 1){
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
            break;
        }
    }
    return loja;
}

tLoja CalculaLucro(tLoja loja){
    int i;
    float totalVendido = 0, totalSalarios = 0, totalComissoes = 0;
    for(i = 0; i < loja.totalVendedores; i++){
        totalVendido += loja.vendedores[i].valor_vendido;
        totalSalarios += loja.vendedores[i].salario;
        totalComissoes += GetComissao(loja.vendedores[i]);
    }
    
    loja.lucro = totalVendido - totalSalarios - totalComissoes - loja.aluguel;
    return loja;
}

void ImprimeRelatorioLoja(tLoja loja){
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);

    int i;
    for(i = 0; i < loja.totalVendedores; i++){
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}
