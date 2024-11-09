#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){
    int qtdDiasMes;

    qtdDiasMes = numeroDiasMes(mes, ano);
    if(dia < 1 || dia > qtdDiasMes || mes < 1 || mes > 12){
        return 0;
    }
    else{
        return 1;
    }
}

int numeroDiasMes(int mes, int ano){
    int bissexto;
    bissexto = verificaBissexto(ano);

    if(mes == 2 && bissexto == 1){
        return 29;
    }
    else if(mes == 2 && bissexto == 0){
        return 28;
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }
    else{
        return 31;
    }

}

int verificaBissexto(int ano){
    return (ano % 4 == 0);
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

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return 1;
    }
    else if(ano1 < ano2){
        return -1;
    }
    else if(ano1 == ano2 && mes1 > mes2){
        return 1;
    }
    else if(ano1 == ano2 && mes1 < mes2){
        return -1;
    }
    else if(ano1 == ano2 && mes1 == mes2 && dia1 > dia2){
        return 1;
    }
    else if(ano1 == ano2 && mes1 == mes2 && dia1 < dia2){
        return -1;
    }
    else if(ano1 == ano2 && mes1 == mes2 && dia1 == dia2){
        return 0;
    }
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int maiorData;
    int qtdDias = 0, diasMes;
    maiorData = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    int difAnos, i;

    if(maiorData == 0){
        return 0;
    }
    else if(maiorData == -1){
        if(mes1 == mes2 && ano1 == ano2){
            qtdDias = dia2 - dia1;
        }
        else if(ano1 == ano2){
            qtdDias = calculaDiasAteMes(mes2, ano2) - calculaDiasAteMes(mes1, ano2);
            qtdDias = qtdDias - dia1 + dia2;
        }
        else{
            difAnos = ano2 - ano1;
            for(i = 0; i <= difAnos; i++){
                if(i == 0){
                    qtdDias = (calculaDiasAteMes(12, ano1) + 31) - calculaDiasAteMes(mes1, ano1);
                }
                else if(i == difAnos){
                    qtdDias += calculaDiasAteMes(mes2, ano2) + dia2 - dia1;
                }
                else{
                    qtdDias += (calculaDiasAteMes(12, ano1 + i) + 31);
                }
            }
        }
    }
    else if(maiorData == 1){
        if(mes1 == mes2 && ano1 == ano2){
            qtdDias = dia1 - dia2;
        }
        else if(ano1 == ano2){
            qtdDias = calculaDiasAteMes(mes1, ano2) - calculaDiasAteMes(mes2, ano2);
            qtdDias = qtdDias + dia1 - dia2;
        }
        else{
            difAnos = ano1 - ano2;
            for(i = 0; i <= difAnos; i++){
                if(i == 0){
                    qtdDias = (calculaDiasAteMes(12, ano2) + 31) - calculaDiasAteMes(mes2, ano2);
                }
                else if(i == difAnos){
                    qtdDias += calculaDiasAteMes(mes1, ano1) + dia1 - dia2;
                }
                else{
                    qtdDias += (calculaDiasAteMes(12, ano2 + i) + 31);
                }
            }
        }
    }

    return qtdDias;
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

