#include "locadora.h"
#include "filme.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora (){
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;
    return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    int i, codFilme, cadastrado = 0;

    for(i = 0; i < locadora.numFilmes; i++){
        codFilme = obterCodigoFilme (locadora.filme[i]);
        if(codFilme == codigo){
            cadastrado = 1;
        }
    }
    return cadastrado;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
*/
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    locadora.filme[locadora.numFilmes] = filme;
    locadora.numFilmes++;
    printf("Filme cadastrado %d - %s\n", filme.codigo, filme.nome);
    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora){
    int codigo;
    int cadastrado = 0, i, recebido = 0;
    tFilme filme;
    
    while(1){
        recebido = scanf("%d,", &codigo);
        if(recebido != 1) break;
        cadastrado = verificarFilmeCadastrado (locadora, codigo);
        if(cadastrado){
            printf("Filme ja cadastrado no estoque\n");
        }
        else if(!(cadastrado)){
            filme = leFilme(codigo);
            locadora = cadastrarFilmeLocadora (locadora, filme);
        }

    }
    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    int estoque, aluguel, cadastrado = 0, qtdAlugados = 0, lucro = 0;

    for(j = 0; j < quantidadeCodigos; j++){
        for(i = 0; i < locadora.numFilmes; i++){
            if(ehMesmoCodigoFilme (locadora.filme[i], codigos[j])){
                cadastrado = 1;
                estoque = obterQtdEstoqueFilme (locadora.filme[i]);
                aluguel = obterQtdAlugadaFilme (locadora.filme[i]);
                if(estoque > 0){
                    locadora.filme[i] = alugarFilme (locadora.filme[i]);
                    qtdAlugados++;
                    lucro += locadora.filme[i].valor;
                }
                else{
                    printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", locadora.filme[i].codigo, locadora.filme[i].nome);
                }
            }
        }
        if(!(cadastrado)){
            printf("Filme %d nao cadastrado.\n", codigos[j]);
        }
        cadastrado = 0;
    }
    
    if(lucro != 0)
    printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, lucro);

    return locadora;
    //printar mensagens.
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora){
    int codigos[MAX_FILMES];
    int i = 0;

    while(1){
        int recebido = scanf("%d", &codigos[i]);
        if(recebido != 1){
            break;
        }
        i++;
    }
    locadora = alugarFilmesLocadora (locadora, codigos, i);
    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    int estoque, aluguel, cadastrado = 0, lucro = 0;

    for(j = 0; j < quantidadeCodigos; j++){
        for(i = 0; i < locadora.numFilmes; i++){
            if(ehMesmoCodigoFilme (locadora.filme[i], codigos[j])){
                cadastrado = 1;
                estoque = obterQtdEstoqueFilme (locadora.filme[i]);
                aluguel = obterQtdAlugadaFilme (locadora.filme[i]);
                if(aluguel > 0){
                    locadora.filme[i] = devolverFilme (locadora.filme[i]);
                    lucro += locadora.filme[i].valor;
                    printf("Filme %d - %s Devolvido!\n", locadora.filme[i].codigo, locadora.filme[i].nome);
                }
                else{
                    printf("Nao e possivel devolver o filme %d - %s.\n", locadora.filme[i].codigo, locadora.filme[i].nome);
                }
            }
        }
        if(!(cadastrado)){
            printf("Filme %d nao cadastrado.\n", codigos[j]);
        }
        cadastrado = 0;
    }
    locadora.lucro += lucro;
    return locadora;
    //printar mensagens.
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int codigos[MAX_FILMES];
    int i = 0;

    while(1){
        int recebido = scanf("%d", &codigos[i]);
        if(recebido != 1){
            break;
        }
        i++;
    }
    locadora = devolverFilmesLocadora (locadora, codigos, i);
    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora){
    int i, j, ordenador;
    tFilme aux;

    for(i = 0; i < locadora.numFilmes; i++){
        for(j = i; j < locadora.numFilmes; j++){
            ordenador = compararNomesFilmes (locadora.filme[i], locadora.filme[j]);
            if(ordenador > 0){
                aux = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = aux;
            }
        }
    }

    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora){
    int i;

    printf("~ESTOQUE~\n");
    for(i = 0; i < locadora.numFilmes; i++){
       printf("%d - %s Fitas em estoque: %d\n", locadora.filme[i].codigo, locadora.filme[i].nome, locadora.filme[i].qtdEstoque);
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora){
    if(locadora.lucro != 0)
    printf("\nLucro total R$%d\n", locadora.lucro);
}

