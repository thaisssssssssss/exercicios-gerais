#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "vector.h"
#include "lista_contato.h"

int main(){
    char caminho[100];
    scanf("%*[^A-Z^a-z]");
    scanf("%s", caminho);
    tListaContato *lista = CriarListaContato();
    CarregarListaContato(lista, caminho);

    int op, fim = 0;;

    while(1){
        printf("1 - Cadastrar contato\n");
        printf("2 - Remover contato\n");
        printf("3 - Realizar busca\n");
        printf("4 - Exibir todos os contatos\n");
        printf("0 - Sair da lista de contatos\n");
        printf("Opcao escolhida:\n");

        scanf("%d", &op);

        switch (op){
            case 0:
                fim = 1;
            break;

            case 1:
                tContato *c = LeContato();
                AdicionarContatoListaContato(lista, c);
            break;

            case 2:
                RemoverContatoListaContato(lista);
            break;
            
            case 3:
                printf("1 - Buscar pelo nome\n");
                printf("2 - Buscar pelo numero de telefone\n");
                printf("Opcao escolhida:\n");
                scanf("%d", &op);
                switch (op)
                {
                case 1:
                    BuscarPorNomeListaContato(lista);
                break;

                case 2:
                    BuscarPorNumeroTelefoneListaContato(lista);
                break;
                
                default:
                    break;
                }
            break;

            case 4:
                ImprimirListaContato(lista);
            break;

            default:
                break;
        }
        if(fim) break;
    }

    char caminho2[100];
    scanf("%*[^A-Z^a-z]");
    scanf("%s", caminho2);
    SalvarListaContato(lista, caminho2);
    DestruirListaContato(lista);
}