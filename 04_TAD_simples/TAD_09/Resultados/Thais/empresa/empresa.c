#include "empresa.h"
#include "funcionario.h"
#include <stdio.h>

/**
 * @brief Cria uma empresa a partir de um id.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id){
    tEmpresa empresa;
    int i;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;
    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa(){
    tEmpresa empresa;
    tFuncionario funcionario;
    int id, qtdFuncionarios, i;

    scanf("%d %d", &id, &qtdFuncionarios);
    empresa = criaEmpresa(id);
    
    for(i = 0; i < qtdFuncionarios; i++){
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
        empresa.qtdFuncionarios++;
    }

    return empresa;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int i;
    int contratado = 0;
    for(i = 0; i < empresa.qtdFuncionarios; i++){
        if(funcionario.id == empresa.funcionarios[i].id){
            contratado = 1;
            empresa.qtdFuncionarios--;
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);    
            break;
        }
    }

    if(contratado == 0){
        empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
    }

    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa){
    int i;
    if(empresa.id != 0)
    printf("Empresa %d:\n", empresa.id);

    for(i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}
