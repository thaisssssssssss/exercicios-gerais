#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int dia, mes, ano;
    int dataValida;
    int bissexto;
    int diasMes;

    int maiorData;
    int diferencaDias;

    scanf("%d/%d/%d", &dia, &mes, &ano);

    dataValida = verificaDataValida(dia, mes, ano);
    if(!(dataValida)){
        printf("A data informada eh invalida\n");
        exit(0);
    }

    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);

    bissexto = verificaBissexto(ano);
    if(bissexto){
        printf("O ano informado eh bissexto\n");
    }
    else{
        printf("O ano informado nao eh bissexto\n");
    }

    diasMes = numeroDiasMes(mes, ano);
    printf("O mes informado possui %d dias\n", diasMes);

    printf("A data seguinte eh: ");
    imprimeProximaData(dia, mes, ano);
}
