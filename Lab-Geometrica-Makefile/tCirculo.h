#ifndef TCIRCULO_H
#define TCIRCULO_H

#include "tPonto.h"

#define PI 3.141592

typedef struct{
  tPonto p;
  float raio;
}tCirculo;


tCirculo criaCirculo(tPonto p, float r);

float calcularArea(tCirculo c);

void imprimeCirculo (tCirculo c);

#endif