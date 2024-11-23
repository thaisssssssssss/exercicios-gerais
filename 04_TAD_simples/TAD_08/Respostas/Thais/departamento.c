#include "departamento.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento departamento;
    strcpy(departamento.c1, c1);
    strcpy(departamento.c2, c2);
    strcpy(departamento.c3, c3);
    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    departamento.media_geral = 0;
    return departamento;
}

void imprimeAtributosDepartamento (tDepartamento depto){
    printf("ATRIBUTOS:\ndepartamento => %s\ndiretor => %s\ncurso1 => %s, media1 => %d\ncurso2 => %s, media2 => %d\ncurso3 => %s, media3 => %d\nmedia geral => %.2f\ndesvio padrao => %.2f\n\n", depto.nome, depto.diretor, depto.c1, depto.m1, depto.c2, depto.m2, depto.c3, depto.m3, calculaMediaGeralDepartamento(depto), calculaDesvioPadraoDepartamento(depto));
}

int validaMediaDepartamento (int media){
    return (media >= 0 && media <= 10);
}

double calculaDesvioPadraoDepartamento(tDepartamento depto){
    double dp = 0;
    double media = calculaMediaGeralDepartamento(depto);
    dp = (pow((depto.m1 - media),2)) + (pow((depto.m2 - media),2)) + (pow((depto.m3 - media),2));
    dp = dp / 3;
    dp = sqrt(dp);
    return dp;
}

double calculaMediaGeralDepartamento(tDepartamento depto){
    double media;
    media = (double)(depto.m1) + (double)(depto.m2) + (double)(depto.m3);
    media = media / 3;
    return media;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    int i, j;
    tDepartamento aux;

    for(i = 0; i < tamanho; i++){
        for(j = i; j < tamanho; j++){
            d[i].media_geral = calculaMediaGeralDepartamento(d[i]);
            d[j].media_geral = calculaMediaGeralDepartamento(d[j]);
            if(d[i].media_geral < d[j].media_geral){
                aux = d[i];
                d[i] = d[j];
                d[j] = aux;
            }
        }
    }
}
