#ifndef TPONTO_H
#define TPONTO_H

#include<stdio.h>
#include<math.h>


typedef struct {
  float x;
  float y;
}tPonto;




tPonto criaPonto(float x, float y);


float distancia (tPonto p1, tPonto p2);

void imprime (tPonto p);

#endif