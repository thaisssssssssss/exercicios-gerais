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
    int codigo;
    char *nome;
    float preco;
    int qtd
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade){
    tProduto *p = malloc(sizeof(struct Produto));
    if(p == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    p->nome = strdup(nome);
    p->codigo = codigo;
    p->preco = preco;
    p->qtd = quantidade;
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
    int codigo, qtd, aux;
    float preco;
    char nome[51];

    fread(&codigo, sizeof(int), 1, arquivo);
    //printf("%d\n", codigo);

    //fread(&aux, sizeof(int), 1, arquivo);
    memset(nome, '\0', 49);
    size_t read_count = fread(nome, sizeof(char), 50, arquivo);
    nome[read_count] = '\0';
    //printf("%s\n", nome);

    fread(&preco, sizeof(float), 1, arquivo);

    fread(&qtd, sizeof(int), 1, arquivo);
    //printf("%d\n", qtd);

    tProduto *p = CriaProduto(codigo, nome, preco, qtd);
    return p;
    
}

// tProduto *LeProduto(FILE *arquivo){
//     if(arquivo == NULL){
//         printf("Arquivo nulo mandado para a leitura de aluno\n");
//         tProduto* nulo = NULL;
//         return nulo;
//     }
    
//     int codigo, qtd;
//     float preco;
//     char nome[51];

//     fread(&codigo, sizeof(int), 1, arquivo);
//     fread(nome, sizeof(char), 50, arquivo);
//     fread(&preco, sizeof(float), 1, arquivo);
//     fread(&qtd, sizeof(int), 1, arquivo);
    
//     tProduto *prod = CriaProduto(codigo, nome, preco, qtd);

//     return prod;
// }

/**
 * @brief Função para verificar se um produto tem estoque.
 * @param produto Um ponteiro para o produto.
 * @return 1 se o produto tem estoque, 0 caso contrário.
 */
int TemEstoqueProduto(tProduto *produto){
    return (produto->qtd > 0);
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto){
    printf("%d;%s;%.2f\n", produto->codigo, produto->nome, produto->preco);
}

