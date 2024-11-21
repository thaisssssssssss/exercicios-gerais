#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <string.h>

int main(){
    int qtdContas, i = 0, j, opcao;
    int num;
    float valor;

    scanf("%d", &qtdContas);
    tConta contas[qtdContas];

    while(1){
        scanf("%d", &opcao);
        
        if(opcao == 0) break;
        else if(opcao == 1){
            scanf("%d %f", &num, &valor);
            for(j = 0; j < qtdContas; j++){
                if(VerificaConta(contas[j], num)){
                    contas[j] = SaqueConta(contas[j], valor);
                }
            }
        }
        else if(opcao == 2){
            scanf("%d %f", &num, &valor);
            for(j = 0; j < qtdContas; j++){
                if(VerificaConta(contas[j], num)){
                    contas[j] = DepositoConta(contas[j], valor);
                }
            }
        }
        else if(opcao == 3){
            tUsuario user;
            char nome[20];
            char cpf[15];

            scanf("%s", nome);
            scanf("%s", cpf);
            scanf("%d", &num);

            user = CriaUsuario(nome, cpf);
            contas[i] = CriaConta(num, user);
            i++;
        }
        else if(opcao == 4){
            printf("===| Imprimindo Relatorio |===\n");
            
            for(j = 0; j < qtdContas; j++){
                ImprimeConta(contas[j]);
            }
        }

    }
    
}