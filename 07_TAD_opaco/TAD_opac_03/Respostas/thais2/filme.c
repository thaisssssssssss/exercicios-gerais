#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"


struct Filme {
    int codigo;
    char nome[20];
    int valor;
    int qtdEstoque;
    int qtdAlugada;
};

tFilme* CriarFilme() {
    tFilme *f = malloc(sizeof(tFilme));
    if (f == NULL) exit(EXIT_FAILURE);
    f->nome = NULL;
    f->codigo = 0;
    f->valor = 0;
    f->qtdEstoque = 0;
    f->qtdAlugada = 0;
    return f;
}

void DestruirFilme(tFilme* filme) {
    if (filme != NULL) {
        free(filme->nome);
        free(filme);
    }
}

int ObterCodigoFilme(tFilme* filme) {
    return filme->codigo;
}

void LeFilme(tFilme* filme, int codigo) {
    filme->codigo = codigo;
    filme->nome = malloc(100 * sizeof(char));
    scanf("%[^,],", filme->nome);
    filme->nome = realloc(filme->nome, sizeof(char) * strlen(filme->nome) + 1);
    scanf("%d,", &filme->valor);
    scanf("%d", &filme->qtdEstoque);
}
