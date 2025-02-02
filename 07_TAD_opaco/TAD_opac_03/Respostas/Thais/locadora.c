#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"
#include "locadora.h"

struct Locadora {
    tFilme *filmes;
    int numFilmes;
    int lucro;
};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora (){
    tLocadora *l = malloc(sizeof(tLocadora));
    if(l == NULL) exit(EXIT_FAILURE);
    l->filmes = NULL;
    l->numFilmes = 0;
    l->lucro = 0;
    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora){
    if(locadora != NULL){
        free(locadora->filmes);
        free(locadora);
    }
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    int i;
    for(i = 0; i < locadora->numFilmes; i++){
        if(EhMesmoCodigoFilme(&locadora->filmes[i], codigo)){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    if(!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))){
        locadora->filmes = realloc(locadora->filmes, (locadora->numFilmes + 1) * sizeof(tFilme));
        locadora->filmes[locadora->numFilmes] = *filme;
        locadora->numFilmes++;
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* locadora){
    tFilme *filme = CriarFilme();
    int codigo;
    scanf("%d", &codigo);
    LeFilme(filme, codigo);
    CadastrarFilmeLocadora(locadora, filme);
    DestruirFilme(filme);
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    for(int i = 0; i < quantidadeCodigos; i++){
        for(int j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(&locadora->filmes[j], codigos[i])){
                AlugarFilme(&locadora->filmes[j]);
                locadora->lucro += ObterValorFilme(&locadora->filmes[j]);
            }
        }
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora){
    int quantidadeCodigos;
    scanf("%d", &quantidadeCodigos);
    int *codigos = malloc(quantidadeCodigos * sizeof(int));
    for(int i = 0; i < quantidadeCodigos; i++){
        scanf("%d", &codigos[i]);
    }
    AlugarFilmesLocadora(locadora, codigos, quantidadeCodigos);
    free(codigos);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    for(int i = 0; i < quantidadeCodigos; i++){
        for(int j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(&locadora->filmes[j], codigos[i])){
                DevolverFilme(&locadora->filmes[j]);
            }
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora){
    int quantidadeCodigos;
    scanf("%d", &quantidadeCodigos);
    int *codigos = malloc(quantidadeCodigos * sizeof(int));
    for(int i = 0; i < quantidadeCodigos; i++){
        scanf("%d", &codigos[i]);
    }
    DevolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
    free(codigos);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora){
    for(int i = 0; i < locadora->numFilmes - 1; i++){
        for(int j = i + 1; j < locadora->numFilmes; j++){
            if(CompararNomesFilmes(&locadora->filmes[i], &locadora->filmes[j]) > 0){
                tFilme temp = locadora->filmes[i];
                locadora->filmes[i] = locadora->filmes[j];
                locadora->filmes[j] = temp;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora){
    for(int i = 0; i < locadora->numFilmes; i++){
        printf("Filme: %s, Código: %d, Estoque: %d, Alugado: %d\n", locadora->filmes[i].nome, locadora->filmes[i].codigo, locadora->filmes[i].qtdEstoque, locadora->filmes[i].qtdAlugada);
    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora){
    printf("Lucro: %d\n", locadora->lucro);
}
