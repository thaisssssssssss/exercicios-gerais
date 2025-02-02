#ifndef FILME_H
#define FILME_H

typedef struct Filme tFilme;

tFilme* CriarFilme();
void DestruirFilme(tFilme* filme);
int ObterCodigoFilme(tFilme* filme);
void LeFilme(tFilme* filme, int codigo);

#endif // FILME_H
