#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"
#include "livro.h"


#define NUM_INICIAL_LIVROS 5

// Estrutura que representa uma biblioteca de livros
typedef struct Biblioteca tBiblioteca;

struct Biblioteca{
    tLivros **livros;
    int qtd;
};

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca(){
    tBiblioteca *b = malloc(sizeof(struct Biblioteca));
    if(b == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    b->livros = NULL;
    b->qtd = 0;

    return b;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca){
    if(biblioteca != NULL){
        if(biblioteca->livros != NULL){
            int i;
            for(i = 0; i < biblioteca->qtd; i++){
                ApagaLivro(biblioteca->livros[i]);
            }
            free(biblioteca->livros);
        }
        free(biblioteca);
    }
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro){
    if(biblioteca->qtd == 0){
        biblioteca->livros = malloc(NUM_INICIAL_LIVROS * sizeof(struct Livros*));
        if(biblioteca->livros == NULL){
            printf("Falha!");
            exit(EXIT_FAILURE);
        }
        biblioteca->livros[biblioteca->qtd] = livro;
        // LerLivro(biblioteca->livros[biblioteca->qtd]);
        biblioteca->qtd++;
    }
    else if(biblioteca->qtd != 0 && biblioteca->qtd % 5 == 0){
        biblioteca->livros = realloc(biblioteca->livros, (biblioteca->qtd + NUM_INICIAL_LIVROS) * sizeof(struct Livros*));
        biblioteca->livros[biblioteca->qtd] = livro;
        // LerLivro(biblioteca->livros[biblioteca->qtd]);
        biblioteca->qtd++;
    }
    else{
        biblioteca->livros[biblioteca->qtd] = livro;
        // LerLivro(biblioteca->livros[biblioteca->qtd]);
        biblioteca->qtd++;
    }
    printf("Livro adicionado com sucesso!\n");
}



/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo){
    int i, j, removido = 0;
    //printf("(%d rem)", biblioteca->qtd);
    for(i = 0; i < biblioteca->qtd; i++){
        if(!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo)){
            //if(biblioteca->qtd != 1){
                for(j = i; j < biblioteca->qtd - 1; j++){
                    biblioteca->livros[j] = biblioteca->livros[j + 1];
                }
            //}
            //else removido = 1;
            removido = 1;
        }
    }
    if(removido){
        ApagaLivro(biblioteca->livros[biblioteca->qtd - 1]);
        printf("Livro removido com sucesso!\n");
        biblioteca->qtd--;
        //printf("(%d)\n", biblioteca->qtd);
    }
    else{
        printf("Livro nao encontrado na biblioteca.\n");
    }
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){
    return (strcmp(getTitulo(livro), titulo));
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){
    int i;
    if(biblioteca->qtd == 0) printf("A biblioteca esta vazia!\n");
    else{
        printf("Lista de Livros na Biblioteca:\n");
        for(i = 0; i < biblioteca->qtd; i++){
            ImprimeLivro(biblioteca->livros[i]);
        }
    }
}
