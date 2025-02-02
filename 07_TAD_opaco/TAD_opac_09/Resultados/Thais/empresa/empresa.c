#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
#include "empresa.h"

struct empresa{
    int id;
    int qtdFuncionarios;
    tFuncionario **funcionarios;
};


/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa(){
    tEmpresa *e = malloc(sizeof(tEmpresa));
    e->funcionarios = NULL;
    e->id = -1;
    e->qtdFuncionarios = -1;
    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa){
    int i, qtd;
    scanf("%d %d", &empresa->id, &qtd);
    empresa->funcionarios = malloc(qtd * sizeof(tFuncionario*));
    
    empresa->qtdFuncionarios = 0;
    for(i = 0; i < qtd; i++){
        empresa->funcionarios[empresa->qtdFuncionarios] = CriaFuncionario();
        LeFuncionario(empresa->funcionarios[empresa->qtdFuncionarios]);
        ContrataFuncionarioEmpresa(empresa, empresa->funcionarios[empresa->qtdFuncionarios]);
    }
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa){
    int i;
    if(empresa != NULL){
        if(empresa->funcionarios != NULL){
            for(i = 0; i < empresa->qtdFuncionarios; i++){
                if(empresa->funcionarios[i] != NULL){
                    ApagaFuncionario(empresa->funcionarios[i]);
                }
            }
            free(empresa->funcionarios);
        }
        free(empresa);
    }
}


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){
     int i, j, contratado = 0;
        for(j = 0; j < empresa->qtdFuncionarios; j++){
            if(GetIdFuncionario(empresa->funcionarios[j]) == GetIdFuncionario(funcionario)){
                printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, GetIdFuncionario(funcionario));
                contratado = 1;
                ApagaFuncionario(empresa->funcionarios[empresa->qtdFuncionarios]);
                break;
            }
        }

    if(!contratado){
        empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
        empresa->qtdFuncionarios++;
    }
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa){
    printf("Empresa %d:\n", empresa->id);
    int i;
    for(i = 0; i < empresa->qtdFuncionarios; i++){
        if(empresa->funcionarios[i] != NULL) ImprimeFuncionario(empresa->funcionarios[i]);
    }
    printf("\n");
}
