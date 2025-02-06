#ifndef PONTOS_H
#define PONTOS_H

#include "pontos.h"

typedef struct pontos_arr tPontos_arr;

tPontos_arr *inicializarTPontos();
void adicionarPonto(tPonto *p, tPontos_arr *tp);
void imprimeLista(tPontos_arr *p);
void carregarPontos(tPontos_arr *p, int qtde);
void liberaLista(tPontos_arr *p);
void reallocaQtdPontos(tPontos_arr *p, int i);
#endif