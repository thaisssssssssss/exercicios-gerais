#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "vector.h"
#include "estabelecimento.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
typedef struct Estabelecimento tEstabelecimento;

struct Estabelecimento{
    Vector *lista;
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

    e->qtd = 0;
    e->lista = VectorConstruct();
    return e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    if(estabelecimento != NULL){
        if(estabelecimento->lista != NULL){
            VectorDestroy(estabelecimento->lista, (void *)DestroiProduto);
            //free(estabelecimento->lista);
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
    VectorPushBack(estabelecimento->lista, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){
    char caminho[100];
    scanf("%s", caminho);

    FILE *f = fopen(caminho, "rb");
    if(f == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fread(&estabelecimento->qtd, sizeof(int), 1, f);
    int i;
    for(i = 0; i < estabelecimento->qtd; i++){
        tProduto *p = LeProduto(f);
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }

    fclose(f);
}

/**
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento){
    float valor = 0, mult = 0, preco = 0;
    int tamanho = VectorSize(estabelecimento->lista);
    int i;
    for(i = 0; i < tamanho; i++){
        preco = GetPrecoProduto(VectorGet(estabelecimento->lista, i));
        mult = GetQuantidadeVendidaProduto(VectorGet(estabelecimento->lista, i));
        valor += preco * mult;
    }
    return valor;
}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento){
    float valor = GetValorTotalVendidoEstabelecimento(estabelecimento);
    float preco = 0, pct;
    int i;
    int tamanho = VectorSize(estabelecimento->lista);

    printf("Valor total vendido: R$ %.2f\n", valor);
    printf("Produtos vendidos:\n");
    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");
    for(i = 0; i < tamanho; i++){
        preco = GetPrecoProduto(VectorGet(estabelecimento->lista, i));
        preco = preco * GetQuantidadeVendidaProduto(VectorGet(estabelecimento->lista, i));
        ImprimeProduto(VectorGet(estabelecimento->lista, i));
        pct = (preco * 100) / valor;
        printf(";%.2f%%\n", pct);
    }
}

