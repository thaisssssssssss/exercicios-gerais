#include <stdio.h>
#include "pessoa.h"
#include <string.h>
#include <stdlib.h>


int main(){
    int qtd, i;
    scanf("%d", &qtd);
    tPessoa p[qtd];
    for(i = 0; i < qtd; i++){
        p[i] = CriaPessoa();
        LePessoa(&p[i]);
    }
    AssociaFamiliasGruposPessoas(p);

    
}