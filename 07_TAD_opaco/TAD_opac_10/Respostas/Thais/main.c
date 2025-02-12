#include <stdio.h>
#include "livro.h"
#include "biblioteca.h"

int main(){
    int qtd;
    scanf("%d", &qtd);
    int i;

    tBiblioteca *b = InicializarBiblioteca();

    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n");
    
    for(i = 0; i < qtd; i++){
        int op;
        scanf("%d", &op);

        if(op ==1 ){
            tLivros *l = CriaLivro();
            LerLivro(l);
            AdicionarLivroNaBiblioteca(b, l);
        }
        else if(op == 2){
            char titulo[100];
            scanf("%s", titulo);
            RemoverLivroDaBiblioteca(b, titulo);
        }
        else if(op == 3){
            ListarLivrosDaBiblioteca(b);
        }
        else{
            printf("Operacao invalida!\n");
            break;
        }
    }

    ApagaBiblioteca(b);
}