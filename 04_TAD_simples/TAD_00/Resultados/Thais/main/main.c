#include "ponto.h"
#include <stdio.h>
#include <math.h>

int main(){
    Ponto p1, p2;
    float x1, y1, x2, y2, distancia;

    scanf("%f %f", &x1, &y1);
    p1 = pto_cria (x1, y1);

    scanf("%f %f", &x2, &y2);
    p2 = pto_cria (x2, y2);

    distancia = pto_distancia (p1, p2);
    printf("%g", distancia);
    return 0;
}