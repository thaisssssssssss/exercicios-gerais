#include "empresa.h"
#include "funcionario.h"
#include <stdio.h>

int main(){
    int qtdEmpresas, i;
    scanf("%d", &qtdEmpresas);
    tEmpresa empresa[qtdEmpresas];

    for(i = 0; i < qtdEmpresas; i++){
        empresa[i] = leEmpresa();
    }
    for(i = 0; i < qtdEmpresas; i++){
        imprimeEmpresa(empresa[i]);
    }
    
    return 0;
}