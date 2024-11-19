#include "ponto.h"
#include <stdio.h>
#include <math.h>

Ponto pto_cria (float x, float y){
    Ponto pto;
    pto = pto_atribui_x (pto, x);
    pto = pto_atribui_y (pto, y);
    return pto;
}

float pto_acessa_x (Ponto p){
    return p.x;
}

float pto_acessa_y (Ponto p){
    return p.y;
}


Ponto pto_atribui_x (Ponto p, float x){
    p.x = x;
    return p;
}

Ponto pto_atribui_y (Ponto p, float y){
    p.y = y;
    return p;
}

float pto_distancia (Ponto p1, Ponto p2){
    float x1, y1, x2, y2;
    float distancia, deltaX, deltaY;

    x1 = pto_acessa_x(p1);
    y1 = pto_acessa_y(p1);
    x2 = pto_acessa_x(p2);
    y2 = pto_acessa_y(p2);

    deltaX = x1 - x2;
    deltaY = y1 - y2;

    distancia = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    return distancia;
}