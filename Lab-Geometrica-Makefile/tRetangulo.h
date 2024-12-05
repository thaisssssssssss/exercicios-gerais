#ifndef TRETANGULO_H
#define TRETANGULO_H
#include "tPonto.h"

typedef struct{
  tPonto p1, p2;
}tRetangulo;

tRetangulo criaRetangulo(tPonto p1, tPonto p2);

#endif