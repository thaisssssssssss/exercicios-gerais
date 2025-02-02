#include "livro.h"
#include "biblioteca.h"
#include <stdio.h>

int main(){
    int operacoes, i, op;
    scanf("%d", &operacoes);

    tLivros livro;
    tBiblioteca biblioteca;

    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");
    biblioteca = inicializarBiblioteca();

    for(i = 0; i < operacoes; i++){
    
        scanf("%d", &op);

        if(op == 1){
            livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }
        else if(op == 2){
            char titulo[100];
            scanf("%s", titulo);
            biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
        }
        else if(op == 3){
            listarLivrosDaBiblioteca(biblioteca);
        }
        else{
            printf("Operacao invalida!\n");
            break;
        }
    
    }

    return 0;
}