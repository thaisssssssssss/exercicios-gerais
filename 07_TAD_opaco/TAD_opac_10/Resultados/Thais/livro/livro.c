#include <stdio.h>
#include "livro.h"
#include <stdlib.h>
#include <string.h>

// Estrutura que representa um livro
typedef struct Livros tLivros;

struct Livros{
    char *titulo;
    char *autor;
    int ano;
};

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro(){
    tLivros *l = malloc(sizeof(struct Livros));
    if(l == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    l->titulo = NULL;
    l->autor = NULL;
    l->ano = -1;

    return l;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro){
    char titulo[100], autor[100];
    scanf("%*[^A-Z^a-z]");
    scanf("%s", titulo);
    scanf("%*[^A-Z^a-z]");
    scanf("%s", autor);
    scanf("%d", &livro->ano);

    livro->titulo = malloc(strlen(titulo) * sizeof(char) + 1);
    if(livro->titulo == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(livro->titulo, titulo);


    livro->autor = malloc(strlen(autor) * sizeof(char) + 1);
    if(livro->autor == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(livro->autor, autor);
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro){
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->ano);
}

/**
 * Retorna o título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será retornado.
 * @return O título do livro.
*/
char *getTitulo(tLivros* livro){
    return livro->titulo;
}

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro){
    if(livro != NULL){
        if(livro->titulo != NULL) free(livro->titulo);
        if(livro->autor != NULL) free(livro->autor);
        free(livro);
    }
}

