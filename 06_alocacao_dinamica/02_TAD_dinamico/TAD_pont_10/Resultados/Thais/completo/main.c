#include <stdio.h>
#include "livro.h"
#include <string.h>
#include <stdlib.h>
#include "biblioteca.h"


// #define MAX_LIVROS 10


// // Estrutura que representa um livro
// typedef struct {
//     char* titulo; // Título do livro
//     char* autor;   // Autor do livro
//     int anoPublicacao; // Ano de publicação do livro
// } tLivros;

// /**
//  * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
//  *
//  * @return Um ponteiro para um livro livro "vazio"
//  */
// tLivros* CriaLivro(){
//      tLivros *l = malloc(sizeof(tLivros));
//     l->titulo = NULL;
//     l->autor = NULL;
//     l->anoPublicacao = -1;
//     return l;
// }

// /**
//  * Lê os atributos de um livro a partir da entrada padrão (teclado).
//  *
//  * @param livro Um ponteiro para um livro que receberá os atributos lidos
//  */
// void LerLivro(tLivros* livro){
//     /** tLivros l;
//     scanf("%*[^A-Z^a-z]");
//     scanf("%[^\n]", l.titulo);
//     scanf("%*[^A-Z^a-z]");
//     scanf("%[^\n]", l.autor);
//     scanf("%d", &l.anoPublicacao);
//     return l; */

//     char titulo[50];
//     char autor[20];

//     scanf("%*[^A-Z^a-z]");
//     scanf("%[^\n]", titulo);
//     scanf("%*[^A-Z^a-z]");
//     scanf("%[^\n]", autor);
    
//     livro->titulo = malloc(sizeof(char) * strlen(titulo) + 1);
//     strcpy(livro->titulo, titulo);
//     livro->autor = malloc(sizeof(char) * strlen(autor) + 1);
//     strcpy(livro->autor, autor);
//     scanf("%d", &livro->anoPublicacao);

// }

// /**
//  * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
//  * 
//  * @param livro Um ponteiro para o livro cujos atributos serão impressos
// */
// void ImprimeLivro(tLivros* livro){
//     printf("Titulo: %s\nAutor: %s\nAno de Publicacao: %d\n", livro->titulo, livro->autor, livro->anoPublicacao);
// }

// /**
//  * Função para liberar toda a memória alocada por um livro
//  * 
//  * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
// */
// void ApagaLivro(tLivros* livro){
//     if(livro != NULL){
//         if(livro->titulo != NULL) free(livro->titulo);
//         if(livro->autor != NULL) free(livro->autor);
//         free(livro);
//     }
// }


// // Estrutura que representa uma biblioteca de livros
// typedef struct {
//     tLivros* livros[MAX_LIVROS]; // Array de livros (Neste exemplo, o máximo suportado será 10)
//     int tamanho; // Número atual de livros na biblioteca
// } tBiblioteca;






// /**
//  * Inicializa uma biblioteca vazia.
//  * Ponteiros são inicializados com NULL; 
//  * @return A biblioteca inicializada.
//  */
// tBiblioteca* InicializarBiblioteca(){
//     tBiblioteca *b = malloc(sizeof(tBiblioteca));
//     *b->livros = NULL;
//     b->tamanho = -1;
// }

// /**
//  * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
//  * Ponteiros são inicializados com NULL; 
//  * @return A biblioteca inicializada.
//  */
// void ApagaBiblioteca(tBiblioteca* biblioteca){
//     if(biblioteca != NULL){
//         int i;
//         if(biblioteca->livros != NULL){
//             for(i = 0; i <= biblioteca->tamanho; i++) ApagaLivro(biblioteca->livros[i]);
//             free(biblioteca->livros);
//         }
//         free(biblioteca);
//     }
// }

// /**
//  * Adiciona um livro à biblioteca.
//  * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
//  * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
//  *
//  * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
//  * @param livro Ponteiro para o livro a ser adicionado.
//  */
// void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro){
//     /**
//      * if(biblioteca.tamanho < MAX_LIVROS - 1){
//         biblioteca.tamanho++;
//         biblioteca.livros[biblioteca.tamanho] = livro;
//         printf("Livro adicionado com sucesso!\n");
//     }
//     else printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
//     return biblioteca;
//      */
//     /**
//      * Locadora->filme = realloc(Locadora->filme, (Locadora->numFilmes + 2) * sizeof(tFilme*));
//         Locadora->filme[Locadora->numFilmes] = CriarFilme();
//         LeFilme(Locadora->filme[Locadora->numFilmes], c);
//      */

//     if(biblioteca->tamanho < MAX_LIVROS - 1){
//         biblioteca->tamanho++;
//         *biblioteca->livros = realloc(biblioteca->livros, (biblioteca->tamanho + 2)* sizeof(tLivros));
//         biblioteca->livros[biblioteca->tamanho] = CriaLivro();
//         biblioteca->livros[biblioteca->tamanho] = livro;
//         printf("Livro adicionado com sucesso!\n");
//     }
//     else printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
// }

// /**
//  * Verifica se o título digitado é igual ao título do livro.
//  * 
//  * @param livro Ponteiro para o livro cujo título será verificado.
//  * @param titulo O título digitado pelo usuário.
//  * @return se o título for igual, retorna 0.
// */
// int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){
//     return (strcmp(livro->titulo, titulo));
// }

// /**
//  * Remove um livro da biblioteca pelo título. 
//  * Se o título for encontrado, imprime "Livro removido com sucesso!",
//  * Senão, imprime "Livro não encontrado na biblioteca."
//  *
//  * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
//  * @param titulo O título do livro a ser removido.
//  */
// void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo){
//     /**
//      *     int i, removido = 0, j;
//     for(i = 0; i <= biblioteca.tamanho; i++){
//         if(!verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo)){
//             biblioteca.livros[i].titulo[0] = '\0';
//             biblioteca.livros[i].autor[0] = '\0';
//             biblioteca.livros[i].anoPublicacao = 0;
//             printf("Livro removido com sucesso!\n\n");
//             removido++;
//             biblioteca.tamanho--;
//             for(j = i; j <= biblioteca.tamanho; j++){
//                 biblioteca.livros[j] = biblioteca.livros[j + 1];
//             }
//             break;
//         }
//     }
//     if(!removido) printf("Livro nao encontrado na biblioteca.\n\n");
//     return biblioteca;
//      */

//     int i, removido = 0, j;
//     for(i = 0; i <= biblioteca->tamanho; i++){
//         if(!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo)){
//             printf("Livro removido com sucesso!\n\n");
//             removido++;
//             biblioteca->tamanho--;
//             for(j = i; j <= biblioteca->tamanho; j++){
//                 biblioteca->livros[j] = biblioteca->livros[j + 1];
//             }
//             ApagaLivro(biblioteca->livros[j+1]);
//             break;
//         }
//     }
//     if(!removido) printf("Livro nao encontrado na biblioteca.\n\n");
// }


// /**
//  * Lista todos os livros presentes na biblioteca.
//  * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
//  *
//  * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
//  */
// void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){
//     if(biblioteca->tamanho == -1) printf("A biblioteca esta vazia!\n");
//     else{
//         int i;
//         printf("Lista de Livros na Biblioteca:\n");
//         for(i = 0; i <= biblioteca->tamanho; i++){
//             ImprimeLivro(biblioteca->livros[i]);
//         }
//     }
// }






int main(){
    int qtd, i, op;
    tBiblioteca *bib = InicializarBiblioteca();
    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");

    scanf("%d", &qtd);
    for(i = 0; i < qtd; i++){
        scanf("%d", &op);

        if(op == 1) {
            tLivros *li = CriaLivro();
            LerLivro(li);
            AdicionarLivroNaBiblioteca(bib, li);
        }
        else if(op == 2){
            char tit[50];
            scanf("%*[^A-Z^a-z]");
            scanf("%[^\n]", tit);
            RemoverLivroDaBiblioteca(bib, tit);
        }
        else if(op == 3){
            ListarLivrosDaBiblioteca(bib);
        }
        else{
            printf("Operacao invalida!\n");
            break;
        }
    }
    ApagaBiblioteca(bib);
    return 0;
}