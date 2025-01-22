#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tPessoa {
    char nome[100];
    struct tPessoa *pai;
    struct tPessoa *mae;
} tPessoa;

tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    return pessoa;
}

int main() {
    tPessoa p[2];
    p[0] = CriaPessoa();
    p[1] = CriaPessoa();

    p[0].mae = (tPessoa *)malloc(sizeof(tPessoa));
    p[0].pai = (tPessoa *)malloc(sizeof(tPessoa));
    
    strcpy(p[0].mae->nome, "Marta");
    strcpy(p[0].pai->nome, "Jorge");
    
    printf("%s", p[0].mae->nome);
    printf("\n%s\n", p[0].pai->nome);

    char nome[100];
    scanf("%s", nome);
    strcpy(p[0].nome, nome);
    
    p[1].mae = (tPessoa *)malloc(sizeof(tPessoa));
    p[1].pai = (tPessoa *)malloc(sizeof(tPessoa));
    
    strcpy(p[1].mae->nome, p[0].nome);
    strcpy(p[1].pai->nome, p[0].nome);
    
    printf("%s", p[1].mae->nome);
    printf("\n%s\n", p[1].pai->nome);
    printf("%s\n", p[0].nome);

    // Libera a memória alocada
    free(p[0].mae);
    free(p[0].pai);
    free(p[1].mae);
    free(p[1].pai);

    return 0;
}
