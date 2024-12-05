#ifndef TTRIANGULO_H
#define TTRIANGULO_H

#include "tPonto.h"

typedef struct{
  tPonto p1, p2, p3;
}tTriangulo;

tTriangulo criaTri(tPonto p1, tPonto p2, tPonto p3);

#endif