#include "empresa.h"
#include <stdio.h>

/**
 * @brief Cria uma empresa a partir de um id.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id){
    tEmpresa e;
    e.id = id;
    e.qtdFuncionarios = 0;
    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa(){
    tEmpresa e;
    tFuncionario f;
    int id, qtd, i;
    scanf("%d %d", &id, &qtd);
    e = criaEmpresa(id);
    
    for(i = 0; i < qtd; i++){
        f = leFuncionario();
        e = contrataFuncionarioEmpresa(e, f);
    }
    return e;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int i, contratado = 0;
    if(empresa.qtdFuncionarios == 0){
        empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
        empresa.qtdFuncionarios++;
    }
    else{
        for(i = 0; i < empresa.qtdFuncionarios; i++){
            if(empresa.funcionarios[i].id == funcionario.id){
                contratado = 1;
                printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, empresa.funcionarios[i].id);
            }
        }
        if(contratado == 0){
            empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
            empresa.qtdFuncionarios++;
        }
    }
    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa){

    printf("Empresa %d:\n", empresa.id);
    int i;
    for(i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}
