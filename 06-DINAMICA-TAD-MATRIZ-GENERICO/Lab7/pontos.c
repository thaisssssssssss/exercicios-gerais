#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESTE_TIPO_ float
#define DESTE_FORMATO_ ".2f" 

#include "pontos.h"


struct ponto{
    DESTE_TIPO_ x;
    DESTE_TIPO_ y;
};

tPonto * CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y){
    tPonto *p = malloc(sizeof(struct ponto));
    p->x = x;
    p->y = y;
}

void ImprimirPonto(tPonto *p){
    char f[14];
    f[0] = '"';
    f[1] = '{';
    f[2] = '%';
    f[3] = '.';
    f[4] = '2';
    f[5] = 'f';
    f[6] = ' ';
    f[7] = '%';
    f[8] = '.';
    f[9] = '2';
    f[10] = 'f';
    f[11] = '}';
    f[12] = '"';
    f[13] = '\0';
    //char formato[10] = " %";
	//strcat (formato, DESTE_FORMATO_);
	//strcat (formato, " ");
    printf(f, p->x, p->y);
    printf("\n");
    //printf(formato, p->y);
}

void LiberarPonto(tPonto *p){
    if(p != NULL) free(p);
}


DESTE_TIPO_ RetornaX(tPonto *p){
    return p->x;
}

DESTE_TIPO_ RetornaY(tPonto *p){
    return p->y;
}