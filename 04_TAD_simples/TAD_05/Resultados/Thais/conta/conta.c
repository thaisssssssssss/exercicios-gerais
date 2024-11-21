#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <string.h>

tConta CriaConta(int numero, tUsuario user){
    tConta conta;
    conta.numero = numero;
    strcpy(conta.user.nome, user.nome);
    strcpy(conta.user.cpf, user.cpf);
    conta.saldo = 0;

    return conta;
}

void ImprimeConta(tConta conta){
    printf("Conta: %d\n", conta.numero);
    printf("Saldo: R$ %.2f\n", conta.saldo);
    ImprimeUsuario(conta.user);
}

int VerificaConta(tConta conta, int numero){
    return (conta.numero == numero);
}

tConta SaqueConta(tConta conta, float valor){
    conta.saldo = conta.saldo - valor;
    return conta;
}

tConta DepositoConta(tConta conta, float valor){
    conta.saldo = conta.saldo + valor;
    return conta;
}
