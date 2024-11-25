#include "filme.h"
#include "locadora.h"
#include <stdio.h>
#include <string.h>

int main(){
    tLocadora locadora;
    locadora = criarLocadora ();

    while(1){
        char operacao[20];
        int recebido = scanf("%s", operacao);
        if(recebido == 0 || recebido == -1){
            break;
        }
        
        if(strcmp(operacao, "Cadastrar") == 0){
            locadora = lerCadastroLocadora (locadora);
        }
        else if(strcmp(operacao, "Alugar") == 0){
            locadora = lerAluguelLocadora (locadora);
        }
        else if(strcmp(operacao, "Devolver") == 0){
            locadora = lerDevolucaoLocadora (locadora);
        }
        else if(strcmp(operacao, "Estoque") == 0){
            locadora = ordenarFilmesLocadora (locadora);
            consultarEstoqueLocadora (locadora);
        }
    }

    consultarLucroLocadora (locadora);
}