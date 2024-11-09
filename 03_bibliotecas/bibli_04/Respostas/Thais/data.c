#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){
    int qtdDiasMes;
    qtdDiasMes = numeroDiasMes(mes, ano);
    return (dia >= 1 && dia <= qtdDiasMes && mes >= 1 && mes <= 12);
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro");
    }
    else if(mes == 2){
        printf("Fevereiro");
    }
    else if(mes == 3){
        printf("Marco");
    }
    else if(mes == 4){
        printf("Abril");
    }
    else if(mes == 5){
        printf("Maio");
    }
    else if(mes == 6){
        printf("Junho");
    }
    else if(mes == 7){
        printf("Julho");
    }
    else if(mes == 8){
        printf("Agosto");
    }
    else if(mes == 9){
        printf("Setembro");
    }
    else if(mes == 10){
        printf("Outubro");
    }
    else if(mes == 11){
        printf("Novembro");
    }
    else if(mes == 12){
        printf("Dezembro");
    }
}

int verificaBissexto(int ano){
    return (ano % 4 == 0);
}

int numeroDiasMes(int mes, int ano){
    int bissexto;
    bissexto = verificaBissexto(ano);

    if(mes == 2){
        return (bissexto == 1) ? 29 : 28;
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }
    else{
        return 31;
    }
}


int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if (ano1 != ano2) {
        return (ano1 > ano2) ? 1 : -1;
    }

    if (mes1 != mes2) {
        return (mes1 > mes2) ? 1 : -1;
    }

    if (dia1 != dia2) {
        return (dia1 > dia2) ? 1 : -1;
    }

    return 0;
}

//reescrito por IA
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    
    // Calcula o número total de dias desde 01/01/0000 até as duas datas
    int diasData1 = ano1 * 365 + calculaDiasAteMes(mes1, ano1) + dia1;
    int diasData2 = ano2 * 365 + calculaDiasAteMes(mes2, ano2) + dia2;

    // Corrigir o total de dias para anos bissextos passados
    diasData1 += (ano1 / 4) - (ano1 / 100) + (ano1 / 400);
    diasData2 += (ano2 / 4) - (ano2 / 100) + (ano2 / 400);

    // Retornar a diferença entre os dias
    return diasData2 - diasData1;
}

int calculaDiasAteMes(int mes, int ano){
    int i, dias = 0;
    if(mes == 1){
        return 0;
    }
    else{
        for(i = 1; i < mes; i++){
            dias += numeroDiasMes(i, ano);
        }
    }
    return dias;
}

void imprimeProximaData(int dia, int mes, int ano){
    if(dia < numeroDiasMes(mes, ano)){
        dia++;
    }
    else{
        dia = 1;
        if(mes == 12){
            mes = 1;
        }
        else{
            mes++;
        }
    }
    
    imprimeData(dia, mes, ano);
}

void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}