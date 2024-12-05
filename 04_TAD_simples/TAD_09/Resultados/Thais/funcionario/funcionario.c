#include "funcionario.h"
#include <stdio.h>

/**
 * @brief Cria um funcionario a partir de valores de nome e salario.
 * 
 * @param id Id do funcionario a ser criado.
 * @param salario Salario do funcionario a ser criado.
 * @return TFuncionario Funcionario criado a partir do nome e salario fornecidos.
 */
tFuncionario criaFuncionario(int id, float salario){
    tFuncionario f;
    f.id = id;
    f.salario = salario;
    return f;
}

/**
 * @brief Le os dados de um funcionario da entrada padrao.
 * 
 * @return TFuncionario Funcionario criado a partir dos dados lidos.
 */
tFuncionario leFuncionario(){
    tFuncionario f;
    int id;
    float salario;
    scanf("%d %f", &id, &salario);
    f = criaFuncionario(id, salario);
    return f;
}

/**
 * @brief Obtem o Id de um funcionario.
 * 
 * @param funcionario Funcionario que deseja obter o id.
 * @return int representando o id do funcionario fornecido.
 */
int getIdFuncionario(tFuncionario funcionario){
    return funcionario.id;
}

/**
 * @brief Imprime todos os dados de um funcionario.
 * 
 * @param funcionario Funcionario a ser impresso no terminal.
 */
void imprimeFuncionario(tFuncionario funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}
