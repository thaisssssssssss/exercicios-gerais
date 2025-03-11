#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "vector.h"

typedef struct ListaContato tListaContato;

struct ListaContato{
    Vector *lista;
    int qtd;
};

/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato(){
    tListaContato *l = malloc(sizeof(struct ListaContato));
    if(l == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    l->qtd = 0;
    l->lista = VectorConstruct();
    return l;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l){
    if(l != NULL){
        VectorDestroy(l->lista, (void *)DestruirContato);
        free(l);
    }
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato){
    int existe = 0, i;
    int tamanho = VectorSize(l->lista);
    for(i = 0; i < tamanho; i++){
        if(ComparaTelefoneContato(VectorGet(l->lista, i), contato)) existe = 1;
        if(ComparaNomeContato(VectorGet(l->lista, i), contato)) existe = 1;
    }

    if(!existe) VectorPushBack(l->lista, contato);
    else{
        printf("Ja existe um contato com esse nome e/ou numero de telefone\n");
        DestruirContato(contato);
    }
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo){
    FILE *fp = fopen(nomeArquivo, "rb");
    if(fp == NULL){
        //printf("Arquivo nao existe!");
        //exit(1);
        return;
    }

    int i;
    fread(&l->qtd, sizeof(int), 1, fp);
    for(i = 0; i < l->qtd; i++){
        tContato *c = CarregarContato(fp);
        AdicionarContatoListaContato(l, c);
    }

    fclose(fp);
}

/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo){
    FILE *fp = fopen(nomeArquivo, "wb");
    // if(fp == NULL){
    //     printf("Arquivo nao existe!");
    //     exit(1);
    // }
    int tamanho = VectorSize(l->lista);
    int i;
    fwrite(&tamanho, sizeof(int), 1, fp);
    for(i = 0; i < tamanho; i++){
        SalvarContato(VectorGet(l->lista, i), fp);
    }

    fclose(fp);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l){
    int tamanho = VectorSize(l->lista);
    unsigned long int n;
    scanf("%*[^0-9]");
    scanf("%lu", &n);
    int i, existe = 0;
    for(i = 0; i < tamanho; i++){
        if(GetTelefoneContato(VectorGet(l->lista, i)) == n){
            existe = 1;
            ImprimirContato(VectorGet(l->lista, i));
            break;
        }
    }
    if(!existe) printf("Contato nao encontrado\n");
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNomeListaContato(tListaContato *l){
    int tamanho = VectorSize(l->lista);
    char nome[100];
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", nome);
    int i, existe = 0;
    for(i = 0; i < tamanho; i++){
        if(strcmp(GetNomeContato(VectorGet(l->lista, i)), nome) == 0){
            existe = 1;
            ImprimirContato(VectorGet(l->lista, i));
            break;
        }
    }
    if(!existe) printf("Contato nao encontrado\n");
}

/**
 * @brief Imprime a lista de contatos na tela.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void ImprimirListaContato(tListaContato *l){
    int tamanho = VectorSize(l->lista);
    int i;
    printf("\nLista de contatos cadastrados\n");
    for(i = 0; i < tamanho; i++){
        ImprimirContato(VectorGet(l->lista, i));
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l){
    int tamanho = VectorSize(l->lista);
    unsigned long int n;
    scanf("%*[^0-9]");
    scanf("%lu", &n);
    int i, existe = 0;
    for(i = 0; i < tamanho; i++){
        if(GetTelefoneContato(VectorGet(l->lista, i)) == n){
            existe = 1;
            DestruirContato(VectorGet(l->lista, i));
            VectorRemove(l->lista, i);
            break;
        }
    }
    if(existe) printf("\nContato removido com sucesso\n");
    else if(!existe) printf("Nao existe um contato cadastrado com esse numero de telefone\n");
}

