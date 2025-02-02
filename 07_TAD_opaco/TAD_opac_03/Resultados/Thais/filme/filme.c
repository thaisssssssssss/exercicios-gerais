#include <stdio.h>
#include "filme.h"
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERES 20

struct Filme{
    int codigo;
    char *nome;
    int valor;
    int qtdEstoque;
    int qtdAlugada;
};

/**
 * @brief Cria um novo filme e define a quantidade alugada como 0.
 * 
 * @return Ponteiro para o filme criado ou encerra caso não seja possível alocar memória.
 */
tFilme* CriarFilme(){
    tFilme *f = malloc(sizeof(tFilme));
    //f->nome = (char*)malloc(sizeof(char));
    f->nome = NULL;
    f->codigo = 0;
    f->valor = 0;
    f->qtdEstoque = 0;
    f->qtdAlugada = 0;
    return f;
}

/**
 * @brief Lê um filme do arquivo de entrada e define o código do filme.
 * 
 * @param filme Ponteiro para o filme a ser lido.
*/
void LeFilme(tFilme *filme, int codigo){
    //char *nome;
    //scanf("%*[^0-9]");
    //scanf("%d", &filme->codigo);
    filme->codigo = codigo;
    scanf("%*[^A-Z^a-z]");
    //nome = malloc(sizeof(char));
    filme->nome = malloc(100 * sizeof(char));
    scanf("%[^,],", filme->nome);
    int tam = strlen(filme->nome);
    filme->nome = realloc(filme->nome, sizeof(char) * tam + 1);
    //printf("(%s)(%d)\n", filme->nome, strlen(filme->nome));
    scanf("%d,", &filme->valor);
    scanf("%d", &filme->qtdEstoque);

    //printf("%d,%s,%d,%d\n", filme->codigo, filme->nome, filme->valor, filme->qtdEstoque);
    /**char *name;
    int codigo, valor, qtdEstoque;
    int tamanho = 0;
    char ch;
    scanf("%*[^0-9]");
    scanf("%d", &codigo);

    scanf("%*[^A-Z^a-z]");
    nome = malloc(sizeof(char));
    scanf("%[^,],", nome);
    name = malloc(sizeof(char) * strlen(nome) + 1);
    printf("%s\n", nome);
    
    scanf("%d,", &valor);
    scanf("%d", &qtdEstoque);
    printf("%d,%s,%d,%d\n", codigo, nome, valor, qtdEstoque);
    **/
}

/**
 * @brief Libera a memória alocada para o filme.
 * 
 * @param filme Ponteiro para o filme a ser destruído.
*/
void DestruirFilme (tFilme* filme){
    if(filme != NULL){
        free(filme->nome);
        free(filme);
    }
}

/**
 * @brief Retorna o código do filme.
 * 
 * @param filme Ponteiro para o filme.
 * @return Código do filme.
*/
int ObterCodigoFilme (tFilme* filme){
    return filme->codigo;
}

/**
 * @brief Imprime o nome do filme.
 * 
 * @param filme Ponteiro para o filme.
*/
void ImprimirNomeFilme (tFilme* filme){
    printf("%s", filme->nome);
}

/**
 * @brief Retorna o valor do filme.
 * 
 * @param filme Ponteiro para o filme.
 * @return Valor do filme.
*/
int ObterValorFilme (tFilme* filme){
    return filme->valor;
}

/**
 * @brief Retorna a quantidade em estoque do filme.
 * 
 * @param filme Ponteiro para o filme.
 * @return Quantidade em estoque do filme.
*/
int ObterQtdEstoqueFilme (tFilme* filme){
    return filme->qtdEstoque;
}

/**
 * @brief Retorna a quantidade alugada do filme.
 * 
 * @param filme Ponteiro para o filme.
 * @return Quantidade alugada do filme.
*/
int ObterQtdAlugadaFilme (tFilme* filme){
    return filme->qtdAlugada;
}

/**
 * @brief Verifica se o filme possui o código passado como parâmetro.
 * 
 * @param filme Ponteiro para o filme.
 * @param codigo Código a ser comparado.
 * @return 1 se o filme possui o código passado como parâmetro, 0 caso contrário.
*/
int EhMesmoCodigoFilme (tFilme* filme, int codigo){
    return (filme->codigo == codigo);
}

/**
 * @brief Incrementa a quantidade alugada e decrementa a quantidade em estoque do filme.
 * 
 * @param filme Ponteiro para o filme.
*/
void AlugarFilme (tFilme* filme){
    filme->qtdAlugada++;
    filme->qtdEstoque--;
}

/**
 * @brief Decrementa a quantidade alugada e incrementa a quantidade em estoque do filme.
 * 
 * @param filme Ponteiro para o filme.
*/
void DevolverFilme (tFilme* filme){
    filme->qtdAlugada--;
    filme->qtdEstoque++;
}

/**
 * @brief Compara dois filmes pelo nome.
 * 
 * @param filme1 Ponteiro para o primeiro filme.
 * @param filme2 Ponteiro para o segundo filme.
 * @return 1 se o nome do primeiro filme for maior que o nome do segundo filme, -1 se o nome do primeiro filme for menor que o nome do segundo filme, 0 se os nomes forem iguais.
*/
int CompararNomesFilmes (tFilme* filme1, tFilme* filme2){
    return strcmp(filme1->nome, filme2->nome);
}

