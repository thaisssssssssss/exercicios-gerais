#include <stdio.h>
#include <stdlib.h>
#include "vendedor.h"
#include "loja.h"
#include <string.h>

int main(){
    int qtd, op, i = 0;
    scanf("%d", &qtd);
    tLoja *l[qtd];

    while(1){
        scanf("%d", &op);
        if(op == 0) break;
        else if(op == 1){
            int id;
            float aluguel;
            scanf("%d %f", &id, &aluguel);
            l[i] = AbreLoja(id, aluguel);
            i++;
        }
        else if(op == 2){
            int idLoja, j;
            char nome[50];
            float salario, pct;
            scanf("%*[^A-Z^a-z]");
            scanf("%s %f %f", nome, &salario, &pct);
            scanf("%d", &idLoja);
            tVendedor *v = RegistraVendedor(nome, salario, pct);
            for(j = 0; j < i; j++){
                if(VerificaIdLoja(l[j], idLoja)){
                    ContrataVendedor(l[j], v);
                }
            }
            //ApagaVendedor(v);
        }
        else if(op == 3){
            int idLoja, j;
            char nome[50];
            float valor;
            scanf("%d %s %f", &idLoja, nome, &valor);
            for(j = 0; j < i; j++){
                if(VerificaIdLoja(l[j], idLoja)){
                    RegistraVenda(l[j], nome, valor);
                }
            }
        }
        else if(op == 4){
            int j;
            for(j = 0; j < i; j++){
                CalculaLucro(l[j]);
                ImprimeRelatorioLoja(l[j]);
            }
        }
    }
        int j;
        for(j = 0; j < i; j++){
            ApagaLoja(l[j]);
        }
    return 0;
}