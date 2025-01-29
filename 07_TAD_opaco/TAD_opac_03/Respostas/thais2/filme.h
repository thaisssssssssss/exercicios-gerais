#ifndef FILME_H
#define FILME_H

typedef struct Filme tFilme;

struct Filme {
    int codigo;
    char *nome;
    int valor;
    int qtdEstoque;
    int qtdAlugada;
};

tFilme* CriarFilme();
void DestruirFilme(tFilme* filme);
int ObterCodigoFilme(tFilme* filme);
void LeFilme(tFilme* filme, int codigo);

#endif // FILME_H
