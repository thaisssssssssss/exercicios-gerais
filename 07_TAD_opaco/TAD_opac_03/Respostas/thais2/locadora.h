#ifndef LOCADORA_H
#define LOCADORA_H

#include "filme.h"

typedef struct Locadora tLocadora;

tLocadora* CriarLocadora();
void DestruirLocadora(tLocadora* locadora);
void CadastrarFilmeLocadora(tLocadora* locadora, tFilme* filme);
int VerificarFilmeCadastrado(tLocadora* locadora, int codigo);

#endif // LOCADORA_H
