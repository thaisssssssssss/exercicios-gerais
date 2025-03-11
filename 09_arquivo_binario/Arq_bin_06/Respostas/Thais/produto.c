#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um produto.
 */
typedef struct Produto tProduto;

struct Produto{
    char *nome;
    int codigo, qtdV;
    float preco;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida){
    tProduto *p = malloc(sizeof(struct Produto));
    if(p == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    p->nome = strdup(nome);
    p->codigo = codigo;
    p->qtdV = quantidadeVendida;
    p->preco = preco;

    return p;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto){
    if(produto != NULL){
        if(produto->nome != NULL) free(produto->nome);
        free(produto);
    }
}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo: 
 * Código (int) 
 * Nome (string) 
 * Preço (float) 
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo){
    int codigo, qtd;
    float preco;
    char nome[50];

    fread(&codigo, sizeof(int), 1, arquivo);
    fread(nome, sizeof(char), 50, arquivo);
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&qtd, sizeof(int), 1, arquivo);

    tProduto *p = CriaProduto(codigo, nome, preco, qtd);
    return p;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco;Quantidade vendida".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto){
    printf("%d;%s;R$ %.2f;%d", produto->codigo, produto->nome, produto->preco, produto->qtdV);
}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto){
    return produto->qtdV;
}

/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
*/
float GetPrecoProduto(tProduto *produto){
    return produto->preco;
}


