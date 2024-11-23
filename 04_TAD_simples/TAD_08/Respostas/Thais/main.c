#include "departamento.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int qtdDepartamentos, i;
    scanf("%d", &qtdDepartamentos);
    tDepartamento departamentos[qtdDepartamentos];

    for(i = 0; i < qtdDepartamentos; i++){
        char nome [STRING_MAX];  
        char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];   
        int m1, m2, m3;     
        char diretor [STRING_MAX];   
        float media_geral;

        scanf("%s", nome);
        scanf("%s", diretor);
        scanf("%s", c1);
        scanf("%s", c2);
        scanf("%s", c3);
        scanf("%d %d %d", &m1, &m2, &m3);

        departamentos[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    ordenaPorMediaDepartamentos(departamentos, qtdDepartamentos);
    for(i = 0; i < qtdDepartamentos; i++){
        imprimeAtributosDepartamento(departamentos[i]);
    }

    return 0;
}