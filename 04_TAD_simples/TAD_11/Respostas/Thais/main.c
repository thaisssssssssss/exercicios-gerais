#include <stdio.h>
#include <string.h>
#include "vendedor.h"
#include "loja.h"

int main(){
    int qtdLojas, op, q = 0;
    scanf("%d", &qtdLojas);
    tLoja lojas[qtdLojas];

    while(1){
        scanf("%d", &op);
        if(op == 0) break;
        else if(op == 1){
            if(q == qtdLojas) printf("Nao eh possivel cadastrar mais lojas\n");
            else{
                int id;
                float aluguel;
                scanf("%d %f", &id, &aluguel);
                lojas[q] = AbreLoja(id, aluguel);
                q++;
            }
        }
        else if(op == 2){
            char nome[50];
            float salario, pct;
            int idLoja;
            scanf("%*[^A-Z^a-z]");
            scanf("%s %f %f", nome, &salario, &pct);
            scanf("%d", &idLoja);
            tVendedor v = RegistraVendedor(nome, salario, pct);

            int i;
            for(i = 0; i < q; i++){
                if(VerificaIdLoja(lojas[i], idLoja)){
                    lojas[i] = ContrataVendedor(lojas[i], v);
                }
            }
        }
        else if(op == 3){
            char nome[50];
            float valor;
            int idLoja;
            scanf("%d %s %f", &idLoja, nome, &valor);

            int i;
            for(i = 0; i < q; i++){
                if(VerificaIdLoja(lojas[i], idLoja)){
                    lojas[i] = RegistraVenda(lojas[i], nome, valor);
                }
            }
        }
        else{
            int i;
            for(i = 0; i < q; i++){
                lojas[i] = CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        }
    }
}