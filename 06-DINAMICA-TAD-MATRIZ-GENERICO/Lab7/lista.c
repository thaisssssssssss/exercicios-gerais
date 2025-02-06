#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESTE_TIPO_ float
#define DESTE_FORMATO_ ".2f" 

#include "pontos.h"
#include "lista.h"

struct pontos_arr{
    tPonto **ponto;
    int qtdPontos;
};

tPontos_arr *inicializarTPontos(){
    tPontos_arr *p = malloc(sizeof(struct pontos_arr));
    p->ponto = malloc(11 * sizeof(struct ponto*));
    p->qtdPontos = 0;
    return p;
}

void adicionarPonto(tPonto *p, tPontos_arr *tp){
    tp->ponto[tp->qtdPontos] = p;
    tp->qtdPontos++;
}

void imprimeLista(tPontos_arr *p){
    int i;
    for(i = 0; i < p->qtdPontos; i++){
        ImprimirPonto(p->ponto[i]);
    }
}

void reallocaQtdPontos(tPontos_arr *p, int i){
    p->ponto = realloc(p->ponto, 10 * i * sizeof(struct ponto*));
}

void carregarPontos(tPontos_arr *p, int qtde){
    DESTE_TIPO_ x = 10.10, y = 20.20;
    int i;
    for(i = 0; i < qtde; i++){
        tPonto * ponto = CriarPonto(x, y);
        adicionarPonto(ponto, p);
        if(i != 0 && i%10==0) reallocaQtdPontos(p, i);
    }
}

void liberaLista(tPontos_arr *p){
    int i;
    if(p != NULL){
        if(p->ponto != NULL){
            for(i = 0; i < p->qtdPontos; i++){
                LiberarPonto(p->ponto[i]);
            }
        }
        free(p->ponto);
        free(p);
    }
}