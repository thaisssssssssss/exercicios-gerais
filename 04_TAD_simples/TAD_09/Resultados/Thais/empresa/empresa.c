#include "empresa.h"
#include "funcionario.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id){
    tEmpresa empresa;
    int i;
    for(i = 0; i < 20; i++){
        empresa.funcionarios[i].id = 0;
    }
    empresa.id = id;
    return empresa;
}

tEmpresa leEmpresa(){
    tEmpresa empresa;
    tFuncionario funcionario;
    int id, qtdFuncionarios, i;

    scanf("%d %d", &id, &empresa.qtdFuncionarios);
    empresa = criaEmpresa(id);

    for(i = 0; i < empresa.qtdFuncionarios; i++){
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
    }
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int i;
    int contratado = 0;
    for(i = 0; i < empresa.qtdFuncionarios; i++){
        if(funcionario.id == empresa.funcionarios[i].id){
            contratado = 1;
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);    
            break;
        }
    }

    if(contratado == 0){
        for(i = 0; i < empresa.qtdFuncionarios; i++){
            if(empresa.funcionarios[i].id == 0){
                empresa.funcionarios[i].id = funcionario.id;
                empresa.funcionarios[i].salario = funcionario.salario;
                break;
            }
        }
    }

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){
    int i;
    printf("Empresa %d:\n", empresa.id);

    for(i = 0; i < empresa.qtdFuncionarios; i++){
        if(empresa.funcionarios[i].id != 0){
            imprimeFuncionario(empresa.funcionarios[i]);
        }
    }
}

