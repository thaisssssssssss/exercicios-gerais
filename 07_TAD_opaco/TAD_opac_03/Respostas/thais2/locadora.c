#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

struct Locadora {
    tFilme **filmes;
    int numFilmes;
    int lucro;
};

tLocadora* CriarLocadora() {
    tLocadora *l = malloc(sizeof(tLocadora));
    if (l == NULL) exit(EXIT_FAILURE);
    l->filmes = malloc(10 * sizeof(tFilme*));
    l->numFilmes = 0;
    l->lucro = 0;
    return l;
}

void DestruirLocadora(tLocadora* locadora) {
    if (locadora != NULL) {
        free(locadora->filmes);
        free(locadora);
    }
}

void CadastrarFilmeLocadora(tLocadora* locadora, tFilme* filme) {
    if (!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))) {
        locadora->filmes = realloc(locadora->filmes, (locadora->numFilmes + 1) * sizeof(tFilme));
        locadora->filmes[locadora->numFilmes] = *filme;
        locadora->numFilmes++;
    }
}

int VerificarFilmeCadastrado(tLocadora* locadora, int codigo) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        if (EhMesmoCodigoFilme(&locadora->filmes[i], codigo)) {
            return 1;
        }
    }
    return 0;
}
