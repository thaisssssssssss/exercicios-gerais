#include <stdio.h>
#include "usuario.h"
#include "conta.h"
#include <string.h>

int main(){
    char *nome;
    char *cpf;

    //printf("Digite uma linha de texto:\n");
    //fgets(buffer, 12 * sizeof(char), stdin);

    int qtdContas;
    scanf("%d", &qtdContas);
    tConta contas[qtdContas];
    int qtd = 0;
    int op;
    int numConta;
    float valor;
    int i;
    while(1){
        scanf("%d", &op);
        if(op == 0) break;

        switch (op){
            case 1:
                scanf("%d %f", &numConta, &valor);
                for(i = 0; i < qtd; i++){
                    if(VerificaConta(contas[i], numConta)) 
                    contas[i] = SaqueConta(contas[i], valor);
                }
                break;
            case 2:
                scanf("%d %f", &numConta, &valor);
                for(i = 0; i < qtd; i++){
                    if(VerificaConta(contas[i], numConta)) 
                    contas[i] = DepositoConta(contas[i], valor);
                }
                break;
            case 3:
                tUsuario user;
                fgets(nome, 50 * sizeof(char), stdin);
                fgets(cpf, 15 * sizeof(char), stdin);
                nome[strcspn(nome, " ")] = '\0';
                cpf[strcspn(cpf, " ")] = '\0';
                scanf("%d", &numConta);
                //scanf("%s %s %d", nome, cpf, &numConta);
                user = CriaUsuario(nome, cpf);
                contas[qtd] = CriaConta(numConta, user);
                qtd++;
                break;
                //fgets(nome, 50 * sizeof(char), stdin);
                //fgets(cpf, 15 * sizeof(char), stdin);
            case 4:
                printf("===| Imprimindo Relatorio |===\n");
                for(i = 0; i < qtd; i++){
                    ImprimeConta(contas[i]);
                }
                printf("\n");
            break;

            default:
                break;
        }
    }
}