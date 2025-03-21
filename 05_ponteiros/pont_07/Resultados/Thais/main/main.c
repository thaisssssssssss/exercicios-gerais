#include <stdio.h>
#include "evento.h"

void imprimeMenu(){
    printf("===== Menu =====\n1 - Cadastrar um evento\n2 - Exibir todos os eventos\n3 - Trocar data de um evento\n4 - Trocar a posicao entre dois eventos\n5 - Sair");
}

int main(){
    Evento eventos[MAX_EVENTOS];
    int numEventos = 0;
    int opcao = 0;

    imprimeMenu();

    while(opcao != 5){
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                cadastrarEvento(eventos, &numEventos);
                printf("Evento cadastrado com sucesso!\n");
                break;
            case 2:
                exibirEventos(eventos, &numEventos);
                break;
            case 3:
                trocarDataEvento(eventos, &numEventos);
                break;
            case 4:
                int indiceA, indiceB;
                scanf("%d %d", &indiceA, &indiceB);
                trocarIndicesEventos(eventos, &indiceA, &indiceB, &numEventos);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
            printf("Opcao invalida!\n");
        }
    }
}