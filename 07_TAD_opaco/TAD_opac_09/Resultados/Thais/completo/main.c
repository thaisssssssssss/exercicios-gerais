#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
#include "empresa.h"

int main(){
int qtd, i;
    scanf("%d", &qtd);
    tEmpresa *e[qtd];
    for(i = 0; i < qtd; i++){
        e[i] = CriaEmpresa();
        LeEmpresa(e[i]);
    }
    for(i = 0; i < qtd; i++){
        ImprimeEmpresa(e[i]);
        ApagaEmpresa(e[i]);
    }
    return 0;
}