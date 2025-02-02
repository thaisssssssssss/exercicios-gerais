#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro(){
     tLivros *l = malloc(sizeof(tLivros));
    l->titulo = NULL;
    l->autor = NULL;
    l->anoPublicacao = -1;
    return l;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro){
    /** tLivros l;
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", l.titulo);
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", l.autor);
    scanf("%d", &l.anoPublicacao);
    return l; */

    char titulo[50];
    char autor[20];

    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", titulo);
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", autor);
    
    livro->titulo = malloc(sizeof(char) * strlen(titulo) + 1);
    strcpy(livro->titulo, titulo);
    livro->autor = malloc(sizeof(char) * strlen(autor) + 1);
    strcpy(livro->autor, autor);
    scanf("%d", &livro->anoPublicacao);

}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro){
    printf("Titulo: %s\nAutor: %s\nAno de Publicacao: %d\n", livro->titulo, livro->autor, livro->anoPublicacao);
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


