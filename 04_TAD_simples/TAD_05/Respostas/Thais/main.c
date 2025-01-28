#include <stdio.h>
#include "usuario.h"
#include "conta.h"
#include <string.h>

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario CriaUsuario(char nome[20], char cpf[15]){
    tUsuario usuario;
    strcpy(usuario.nome, nome);
    strcpy(usuario.cpf, cpf);
    return usuario;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}

/**
 * @brief Cria uma nova conta bancária.
 * @param numero Número da conta.
 * @param user Usuário da conta.
 * @return A nova conta criada.
 */
tConta CriaConta(int numero, tUsuario user){
    tConta conta;
    conta.numero = numero;
    conta.user = CriaUsuario(user.nome, user.cpf);
    conta.saldo = 0;
    return conta;
}

/**
 * @brief Imprime os dados de uma conta bancária.
 * @param conta Conta bancária a ser impressa.
 */
void ImprimeConta(tConta conta){
    printf("Conta: %d\n", conta.numero);
    printf("Saldo: R$ %.2f\n", conta.saldo);
    ImprimeUsuario(conta.user);
}

/**
 * @brief Compara o número de uma conta bancária com um número dado.
 * @param conta Conta bancária a ser comparada.
 * @param numero Número a ser comparado.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int VerificaConta(tConta conta, int numero){
    return (conta.numero == numero);
}

/**
 * @brief Realiza um saque em uma conta bancária.
 * @param conta Conta bancária a ser sacada.
 * @param valor Valor a ser sacado.
 * @return A conta com o novo saldo após o saque.
 */
tConta SaqueConta(tConta conta, float valor){
    conta.saldo = conta.saldo - valor;
    return conta;
}

/**
 * @brief Realiza um depósito em uma conta bancária.
 * @param conta Conta bancária a ser depositada.
 * @param valor Valor a ser depositado.
 * @return A conta com o novo saldo após o depósito.
 */
tConta DepositoConta(tConta conta, float valor){
    conta.saldo = conta.saldo + valor;
    return conta;
}






int main(){
    char nome[50];
    char cpf[15];

    //printf("Digite uma linha de texto:\n");
    //fgets(buffer, 12 * sizeof(char), stdin);

    int qtdContas;
    scanf("%d", &qtdContas);
    tConta contas[qtdContas];
    int qtd = 0;
    int op;
    int numConta;
    float valor;
    int i;
    while(1){
        scanf("%d/n", &op);
        if(op == 0) break;

        switch (op){
            case 1:
                scanf("%d %f", &numConta, &valor);
                for(i = 0; i < qtd; i++){
                    if(VerificaConta(contas[i], numConta)) 
                    contas[i] = SaqueConta(contas[i], valor);
                }
                break;
            case 2:
                scanf("%d %f", &numConta, &valor);
                for(i = 0; i < qtd; i++){
                    if(VerificaConta(contas[i], numConta)) 
                    contas[i] = DepositoConta(contas[i], valor);
                }
                break;
            case 3:
                tUsuario user;
                //fgets(nome, sizeof(nome), stdin);
                //fgets(cpf, sizeof(cpf), stdin);
                //nome[strcspn(nome, " ")] = '\0';
                //cpf[strcspn(cpf, " ")] = '\0';
                //scanf("%d", &numConta);
                scanf("%s %s %d", nome, cpf, &numConta);
                user = CriaUsuario(nome, cpf);
                contas[qtd] = CriaConta(numConta, user);
                qtd++;
                break;
                //fgets(nome, 50 * sizeof(char), stdin);
                //fgets(cpf, 15 * sizeof(char), stdin);
            case 4:
                printf("===| Imprimindo Relatorio |===\n");
                for(i = 0; i < qtd; i++){
                    ImprimeConta(contas[i]);
                }
                printf("\n");
            break;

            default:
                break;
        }
    }
}