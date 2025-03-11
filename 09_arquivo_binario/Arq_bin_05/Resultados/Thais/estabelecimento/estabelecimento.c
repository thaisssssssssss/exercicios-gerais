#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "vector.h"
#include "estabelecimento.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
typedef struct Estabelecimento tEstabelecimento;

struct Estabelecimento{
    Vector *vetor;
    int qtd;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento *e = malloc(sizeof(struct Estabelecimento));
    if(e == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    e->vetor = VectorConstruct();
    return e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    if(estabelecimento != NULL){
        if(estabelecimento->vetor != NULL){
            VectorDestroy(estabelecimento->vetor, DestroiProduto);
            //free(estabelecimento->vetor);
        }
        free(estabelecimento);
    }
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){
    VectorPushBack(estabelecimento->vetor, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){
    char nomeEs[100];
    scanf("%s", nomeEs);

    FILE *fp = fopen(nomeEs, "rb");
    if(fp == NULL){
        printf("Falha ao abrir!");
        exit(1);
    }

    fread(&estabelecimento->qtd, sizeof(int), 1, fp);
    int i;
    for(i = 0; i < estabelecimento->qtd; i++){
        tProduto *p = LeProduto(fp);
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }

    fclose(fp);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento){
    int i, falta = 0;
    printf("Produtos em falta:\nCodigo;Nome;Preco\n");
    for(i = 0; i < estabelecimento->qtd; i++){
        if(!TemEstoqueProduto(VectorGet(estabelecimento->vetor, i))){
            ImprimeProduto(VectorGet(estabelecimento->vetor, i));
            falta++;
        }
    }
    if(!falta) printf("Nao ha produtos em falta!\n");
}
