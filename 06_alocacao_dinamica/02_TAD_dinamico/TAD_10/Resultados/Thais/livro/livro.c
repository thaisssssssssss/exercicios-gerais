#include <stdio.h>
#include "livro.h"
#include <string.h>

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro(){
    tLivros l;
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", l.titulo);
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", l.autor);
    scanf("%d", &l.anoPublicacao);
    return l;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro O livro cujos atributos serão impressos
*/
void imprimeLivro(tLivros livro){
    printf("Titulo: %s\nAutor: %s\nAno de Publicacao: %d\n", livro.titulo, livro.autor, livro.anoPublicacao);
}


