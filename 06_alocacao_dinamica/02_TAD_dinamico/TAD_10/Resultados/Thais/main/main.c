#include <stdio.h>
#include "livro.h"
#include <string.h>
#include "biblioteca.h"

int main(){
    int qtd, i, op;
    tBiblioteca bib = inicializarBiblioteca();
    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");

    scanf("%d", &qtd);
    for(i = 0; i < qtd; i++){
        scanf("%d", &op);

        if(op == 1) {
            tLivros li = lerLivro();
            bib = adicionarLivroNaBiblioteca(bib, li);
        }
        else if(op == 2){
            char tit[50];
            scanf("%*[^A-Z^a-z]");
            scanf("%[^\n]", tit);
            bib = removerLivroDaBiblioteca(bib, tit);
        }
        else if(op == 3){
            listarLivrosDaBiblioteca(bib);
        }
        else{
            printf("Operacao invalida!\n");
            break;
        }
    }
    return 0;
}