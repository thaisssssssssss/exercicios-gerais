#include <stdio.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

int main(){
    tGerenciador *g = CriaGerenciador();
    int op;
    printf("tad_gen_02\n");
    while(1){
        printf("\nEscolha uma opcao:\n");
        printf("    (1) Cadastrar um novo pacote\n");
        printf("    (2) Imprimir um pacote específico\n");
        printf("    (3) Imprimir todos os pacotes e sair\n");
        scanf("%d", &op);
        if(op == 1){
            int tipo, qtd;
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d", &tipo, &qtd);
            tPacote *p;
            if(tipo == 0 || tipo == 1){
                if(tipo == INT) p = CriaPacote(INT, qtd);
                else p = CriaPacote(CHAR, qtd);
                LePacote(p);
                AdicionaPacoteNoGerenciador(g, p);
            }
            else printf("\nDigite um tipo valido!\n");
        }
        else if(op == 2){
            int idx;
            scanf("%d", &idx);
            ImprimirPacoteNoIndice(g, idx);
        }
        else if(op == 3){
            ImprimirTodosPacotes(g);
            break;
        }
        else printf("Escolha uma opcao valida para o menu!\n");
    }
    DestroiGerenciador(g);
    return 0;
}