#include "biblioteca.h"
#include "livro.h"
#include <stdio.h>
#include <string.h>

/**
 * Inicializa uma biblioteca vazia.
 *
 * @return A biblioteca inicializada.
 */
tBiblioteca inicializarBiblioteca(){
    tBiblioteca b;
    b.tamanho = -1;
    int i;
    for(i = 0; i < MAX_LIVROS; i++){
        b.livros[i].titulo[0] = '\0';
    }
    return b;
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca A biblioteca onde o livro será adicionado.
 * @param livro O livro a ser adicionado.
 * @return A biblioteca atualizada com o livro adicionado.
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro){
    if(biblioteca.tamanho < MAX_LIVROS - 1){
        biblioteca.tamanho++;
        biblioteca.livros[biblioteca.tamanho] = livro;
        printf("Livro adicionado com sucesso!\n");
    }
    else printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");

    return biblioteca;
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca A biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 * @return A biblioteca atualizada após a remoção do livro.
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo){
    int i, removido = 0, j;
    for(i = 0; i <= biblioteca.tamanho; i++){
        if(!verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo)){
            biblioteca.livros[i].titulo[0] = '\0';
            biblioteca.livros[i].autor[0] = '\0';
            biblioteca.livros[i].anoPublicacao = 0;
            printf("Livro removido com sucesso!\n\n");
            removido++;
            biblioteca.tamanho--;
            for(j = i; j <= biblioteca.tamanho; j++){
                biblioteca.livros[j] = biblioteca.livros[j + 1];
            }
            break;
        }
    }
    if(!removido) printf("Livro nao encontrado na biblioteca.\n\n");
    return biblioteca;
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro O livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo){
    return (strcmp(livro.titulo, titulo));
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca A biblioteca cujos livros serão listados.
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca){
    if(biblioteca.tamanho == -1) printf("A biblioteca esta vazia!\n");
    else{
        int i;
        printf("Lista de Livros na Biblioteca:\n");
        for(i = 0; i <= biblioteca.tamanho; i++){
            imprimeLivro(biblioteca.livros[i]);
        }
    }
}


