#include "biblioteca.h"
#include <string.h>
#include <stdio.h>

tBiblioteca inicializarBiblioteca(){
    tBiblioteca biblioteca;
    int i;

    for(i = 0; i < MAX_LIVROS; i++){
        biblioteca.livros[i].titulo[0] = '\0';
        biblioteca.livros[i].autor[0] = '\0';
        biblioteca.livros[i].anoPublicacao = 0;
    }
    biblioteca.tamanho = 0;

    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro){
    int i;

    if(biblioteca.tamanho <= 9){
        for(i = 0; i < MAX_LIVROS; i++){
            if(biblioteca.livros[i].titulo[0]== '\0'){
                strcpy(biblioteca.livros[i].titulo, livro.titulo);
                strcpy(biblioteca.livros[i].autor, livro.autor);
                biblioteca.livros[i].anoPublicacao = livro.anoPublicacao;
                break;
            }
        }
        printf("Livro adicionado com sucesso!\n");
        biblioteca.tamanho++;
    }
    else{
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }

    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo){
    int i, removeu = 0;

    for(i = 0; i < MAX_LIVROS; i++){
        if(!(verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo))){
            biblioteca.livros[i].titulo[0] = '\0';
            biblioteca.livros[i].autor[0] = '\0';
            biblioteca.livros[i].anoPublicacao = 0;
            biblioteca.tamanho = biblioteca.tamanho - 1;
            removeu = 1;
            printf("Livro removido com sucesso!\n");
            break;
        }
    }

    if(removeu == 0){
        printf("Livro nao encontrado na biblioteca.\n");
    }

    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo){
    return (strcmp(livro.titulo, titulo));
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca){
    if(biblioteca.tamanho == 0){
        printf("A biblioteca esta vazia!");
    }
    else{
        printf("\nLista de Livros na Biblioteca:\n");
        int i;
        for(i = 0; i < MAX_LIVROS; i++){
            if(biblioteca.livros[i].titulo[0] != '\0'){
                imprimeLivro(biblioteca.livros[i]);
            }
        }
    }
}

