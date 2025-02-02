#include <stdio.h>
#include <stdlib.h>
#include "vendedor.h"
#include <string.h>
#include "loja.h"

struct Loja{
    int id;
    int maxVendedores;
    int totalVendedores;
    float aluguel;
    float lucro;
    tVendedor **vendedores;
};

/**
 * @brief Abre uma nova loja.
 * 
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja com os dados da loja aberta.
 */
tLoja* AbreLoja(int id, float aluguel){
    tLoja *l = malloc(sizeof(tLoja));
    l->id = id;
    l->totalVendedores = 0;
    l->maxVendedores = 10;
    l->aluguel = aluguel;
    l->lucro = 0;
    l->vendedores = malloc(l->maxVendedores * sizeof(tVendedor*));
    return l;
}

/**
 * @brief Libera a memória alocada para uma loja.
 * 
 * @param loja Ponteiro para uma loja a ser apagado.
 */
void ApagaLoja(tLoja* loja){
    if(loja != NULL){
        if(loja->vendedores != NULL){
            int i;
            for(i = 0; i < loja->totalVendedores; i++){
                ApagaVendedor(loja->vendedores[i]);
            }
            free(loja->vendedores);
        }
        free(loja);
    }
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja* loja, int id){
    return (loja->id == id);
}

/**
 * @brief Contrata um novo vendedor para a loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
void ContrataVendedor(tLoja* loja, tVendedor* vendedor){
    //loja->vendedores[loja->totalVendedores] = malloc(sizeof(tVendedor));
    loja->vendedores[loja->totalVendedores] = vendedor;
    loja->totalVendedores++;
    //ApagaVendedor(vendedor);
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
void RegistraVenda(tLoja* loja, char* nome, float valor){
    int i;
    for(i = 0; i < loja->totalVendedores; i++){
        if(VerificaNomeVendedor(loja->vendedores[i], nome)){
            ContabilizaVenda(loja->vendedores[i], valor);
        }
    }
}

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
void CalculaLucro(tLoja* loja){
    float r = 0, g = 0;
    int i;
    for(i = 0; i < loja->totalVendedores; i++){
        r += GetTotalVendido(loja->vendedores[i]);
        g += GetTotalRecebido(loja->vendedores[i]);
    }
    loja->lucro = r - g - loja->aluguel;
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja* loja){
    int i;
    CalculaLucro(loja);
    printf("Loja %d: Lucro total: R$ %.2f\n", loja->id, loja->lucro);
    for(i = 0; i < loja->totalVendedores; i++){
        ImprimeRelatorioVendedor(loja->vendedores[i]);
    }
}
