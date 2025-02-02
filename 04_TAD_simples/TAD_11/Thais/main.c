#include "vendedor.h"
#include "loja.h"
#include <stdio.h>
#include <string.h>

int main(){
    int qtdLojas, op, i = -1, j;
    int id;
    float aluguel, salario, prct_comissao, valor; 
    scanf("%d", &qtdLojas);
    tLoja lojas[qtdLojas];

    while(1){
        scanf("%d", &op);

        if(op == 0){
            break;
        }
        else if(op == 1){
            i++;
            scanf("%d %f", &id, &aluguel);
            lojas[i] = AbreLoja(id, aluguel);
        }
        else if(op == 2){
            tVendedor vendedor;
            char nome[50];  
            scanf("%s %f %f", nome , &salario, &prct_comissao);
            vendedor = RegistraVendedor(nome, salario, prct_comissao);

            scanf("%d", &id);
            for(j = 0; j <= i; j++){
                if(VerificaIdLoja(lojas[j], id)){
                    lojas[j] = ContrataVendedor(lojas[j], vendedor);
                }
            }
        }
        else if(op == 3){
            char nome[50];  
            scanf("%d %s %f", &id, nome, &valor);

            for(j = 0; j <= i; j++){
                if(VerificaIdLoja(lojas[j], id)){
                    lojas[j] = RegistraVenda(lojas[j], nome, valor);
                }
            }

        }
        else if(op == 4){
             for(j = 0; j <= i; j++){    
                lojas[j] = CalculaLucro(lojas[j]);
                ImprimeRelatorioLoja(lojas[j]);
            }
        }

    }
    return 0;
}