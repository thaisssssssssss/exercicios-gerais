#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "biblioteca.h"

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca(){
    tBiblioteca *b = (tBiblioteca*)malloc(sizeof(tBiblioteca));
    b->tamanho = -1;
    for(int i = 0; i < MAX_LIVROS; i++){
        b->livros[i] = NULL;
    }
    return b;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca){
    if(biblioteca != NULL){
        int i;
        //if(biblioteca->livros != NULL){
            for(i = 0; i <= biblioteca->tamanho; i++) ApagaLivro(biblioteca->livros[i]);
        //}
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
    if(biblioteca->tamanho < MAX_LIVROS - 1){
        biblioteca->tamanho++;
        biblioteca->livros[biblioteca->tamanho] = livro;
        printf("Livro adicionado com sucesso!\n");
    }
    else printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
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
    int i, removido = 0, j;
    for(i = 0; i <= biblioteca->tamanho; i++){
        if(!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo)){
            printf("Livro removido com sucesso!\n\n");
            ApagaLivro(biblioteca->livros[i]);
            removido++;
            biblioteca->tamanho--;
            for(j = i; j <= biblioteca->tamanho; j++){
                biblioteca->livros[j] = biblioteca->livros[j + 1];
            }
            biblioteca->livros[j+1] = NULL;
            break;
        }
    }
    if(!removido) printf("Livro nao encontrado na biblioteca.\n\n");
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){
    return (strcmp(livro->titulo, titulo));
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){
    if(biblioteca->tamanho == -1) printf("A biblioteca esta vazia!\n");
    else{
        int i;
        printf("Lista de Livros na Biblioteca:\n");
        for(i = 0; i <= biblioteca->tamanho; i++){
            ImprimeLivro(biblioteca->livros[i]);
        }
    }
}


