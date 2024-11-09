#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;
    int dataValida;
    int maiorData;
    int diferencaDias;

    scanf("%d/%d/%d\n", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    dataValida = verificaDataValida(dia1, mes1, ano1);
    if(!(dataValida)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(0);
    }

    dataValida = verificaDataValida(dia2, mes2, ano2);
    if(!(dataValida)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(0);
    }

    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);
    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    maiorData = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    if(maiorData == 0){
        printf("As datas sao iguais\n");
    }
    else if(maiorData == -1){
        printf("A primeira data eh mais antiga\n");
    }
    else if(maiorData == 1){
        printf("A segunda data eh mais antiga\n");
    }

    diferencaDias = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
    printf("A diferenca em dias entre as datas eh: %02d dias\n", diferencaDias);
}
