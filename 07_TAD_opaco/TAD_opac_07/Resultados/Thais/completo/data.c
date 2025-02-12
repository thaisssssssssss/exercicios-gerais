#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct Data tData;

struct Data{
    int dia, mes, ano;
};
/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData(){
    tData *data = malloc(sizeof(struct Data));
    if(data == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    data->dia = -1;
    data->mes = -1;
    data->ano = -1;

    return data;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data){
    scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data){
    if(data != NULL) free(data);
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data){
    return (data->mes >= 1 && data->mes <= 12 && data->dia >= 1 && data->dia <= NumeroDiasMes(data));
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data){
    switch (data->mes)
    {
    case 1:
        printf("Janeiro");
    break;

    case 2:
        printf("Fevereiro");
    break;

    case 3:
        printf("Marco");
    break;

    case 4:
        printf("Abril");
    break;

    case 5:
        printf("Maio");
    break;

    case 6:
        printf("Junho");
    break;

    case 7:
        printf("Julho");
    break;

    case 8:
        printf("Agosto");
    break;

    case 9:
        printf("Setembro");
    break;

    case 10:
        printf("Outubro");
    break;

    case 11:
        printf("Novembro");
    break;

    case 12:
        printf("Dezembro");
    break;

    default:
        break;
    }
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data){
    // Primeira data: 28 de Janeiro de 2002

    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data){
    return (data->ano % 4 == 0);
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data){
    if(data->mes == 2){
        if(VerificaBissexto(data)) return 29;
        else return 28;
    }
    else if(data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) return 30;
    else return 31;
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData* data1, tData* data2){
    if(data1->ano == data2->ano){
        if(data1->mes == data2->mes){
            if(data1->dia == data2->dia) return 0;
            else if(data1->dia > data2->dia) return 1;
            else return -1;
        }
        else if(data1->mes > data2->mes) return 1;
        else return -1;
    }
    else if(data1->ano > data2->ano) return 1; // 1 mais nova
    else return -1; // 1 mais velha

}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData* data){
    int i, dias = 0;
    tData d;
    d.ano = data->ano;
    for(i = 1; i < data->mes; i++){
        d.mes = i;
        dias += NumeroDiasMes(&d);
    }
    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2){
    int dias = 0;
    if(ComparaData(data1, data2) == 0) dias = 0;
    else if(ComparaData(data1, data2) > 0){
        int anos = 0, i, d1, d2;
        tData d;
        for(i = data2->ano; i < data1->ano; i++){
            d.ano = i;
            if(VerificaBissexto(&d)) anos += 366;
            else anos += 365;
        }
        d1 = CalculaDiasAteMes(data1) + data1->dia;
        d2 = CalculaDiasAteMes(data2) + data2->dia;

        dias = anos - d2 + d1;
    }
    else{
        int anos = 0, i, d1, d2;
        tData d;
        for(i = data1->ano; i < data2->ano; i++){
            d.ano = i;
            if(VerificaBissexto(&d)) anos += 366;
            else anos += 365;
        }
        d1 = CalculaDiasAteMes(data1) + data1->dia;
        d2 = CalculaDiasAteMes(data2) + data2->dia;

        //printf("(%d)\n", d2);
        dias = anos + d2 - d1;
    }
    return dias;
}

