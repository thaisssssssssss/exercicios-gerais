#include <stdio.h>
#include <stdlib.h>
#include "locadora.h"
#include <string.h>
#include "filme.h"


/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora (){
    tLocadora *l = malloc(sizeof(tLocadora));
    if(l == NULL) exit(EXIT_FAILURE);
    //l->filme = NULL;
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
        int i;
        for(i = 0; i < locadora->numFilmes; i++){
            free(locadora->filme[i]);
        }
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
        if(EhMesmoCodigoFilme(locadora->filme[i], codigo)) return 1;
    }
    return 0;
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora){
    char codigo = 0;
    int c;
    while(1){
        //scanf("%*[0-9]");
        scanf("%*[^0-9^#]");
        scanf("%c", &codigo);
        printf("(%c)\n", codigo);
        if(codigo == '#') break;
        scanf("%*[^A-Z^a-z]");
        c = codigo - '0';
        Locadora->filme = realloc(Locadora->filme, (Locadora->numFilmes + 2) * sizeof(tFilme*));
        Locadora->filme[Locadora->numFilmes] = CriarFilme();
        LeFilme(Locadora->filme[Locadora->numFilmes], c);
        Locadora->numFilmes++;
    }
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    if(!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))) LerCadastroLocadora(locadora);
    else{
        //terminar
    }
}


/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j, alugado = 0;
    for(i = 0; i < locadora->numFilmes; i++){
        for(j = 0; j < quantidadeCodigos; j++){
            if(EhMesmoCodigoFilme(locadora->filme[i], codigos[j])){
                if(ObterQtdEstoqueFilme(locadora->filme[i]) > 0) {
                    AlugarFilme(locadora->filme[i]);
                    alugado++;
                }
            }
        }
    }
    if(alugado == 0){

    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora){
    int resultado, c, i = 0;
    //int *codigo = malloc(sizeof(int));
    int codigo[20];
    while(1){
        resultado = scanf("%d", &c);
        if(resultado != 1) break;
        
        codigo[i] = c;
        i++;
        //codigo = realloc(codigo, i * sizeof(int) + 2);
    }
    AlugarFilmesLocadora(locadora, codigo, i);
    //if(codigo != NULL) free(codigo);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j, devolvido = 0;
    for(i = 0; i < locadora->numFilmes; i++){
        for(j = 0; j < quantidadeCodigos; j++){
            if(EhMesmoCodigoFilme(locadora->filme[i], codigos[j])){
                if(ObterQtdAlugadaFilme(locadora->filme[i]) > 0) {
                    DevolverFilme(locadora->filme[i]);
                    devolvido++;
                }
            }
        }
    }
    if(devolvido == 0){

    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora){
    int resultado, c, i = 0;;
    //int *codigo = malloc(sizeof(int));
    int codigo[20];
    while(1){
        resultado = scanf("%d", &c);
        if(resultado != 1) break;
        
        codigo[i] = c;
        i++;
        //codigo = realloc(codigo, i * sizeof(int) + 2);
    }
    DevolverFilmesLocadora(locadora, codigo, i);
    //if(codigo != NULL) free(codigo);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora){
    int i, j;
    tFilme *aux = CriarFilme();
    for(i = 0; i < locadora->numFilmes; i++){
        for(j = i; j < locadora->numFilmes; j++){
            if(CompararNomesFilmes(locadora->filme[i], locadora->filme[j]) == 1){
                aux = locadora->filme[i];
                locadora->filme[i] = locadora->filme[j];
                locadora->filme[j] = aux;
            }
        }
    }
    DestruirFilme(aux);
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora){
    OrdenarFilmesLocadora(locadora);
    int i;
    printf("~ESTOQUE~\n");
    for(i = 0; i < locadora->numFilmes; i++){
        printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora){
    //Total de filmes alugados: 2 com custo de R$15
}


/**int main(){
    tLocadora *l;
    int i = 0;
        l = CriarLocadora();
    //while(i < 5){
        LerCadastroLocadora(l);
        ConsultarEstoqueLocadora(l);
        i++;
    //}
}**/
