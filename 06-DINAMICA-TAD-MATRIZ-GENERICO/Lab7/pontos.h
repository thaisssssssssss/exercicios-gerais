#ifndef GEOMETRICA_H
#define GEOMETRICA_H
//#define DESTE_TIPO_ float


typedef struct ponto tPonto;

tPonto * CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y);
void ImprimirPonto(tPonto *p);
void LiberarPonto(tPonto *p);
DESTE_TIPO_ RetornaX(tPonto *p);
DESTE_TIPO_ RetornaY(tPonto *p);

#endif