#include "usuario.h"
#include <string.h>
#include <stdio.h>

tUsuario CriaUsuario(char nome[20], char cpf[15]){
    tUsuario user;
    strcpy(user.nome, nome);
    strcpy(user.cpf, cpf);
    return user;
}

void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n\n", user.cpf);
}
