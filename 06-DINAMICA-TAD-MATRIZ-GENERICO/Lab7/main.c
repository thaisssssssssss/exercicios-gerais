#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DESTE_TIPO_ float

#include "lista.h"
#include "pontos.h"

int main(int argc, char **argv){

    if (argc != 2) {
        printf("Uso: %s <quantidade de pontos>\n", argv[0]);
        return 1;
    } 
    int qtde = atoi(argv[1]);
    srand(time(NULL));

    tPontos_arr * lista = inicializarTPontos();
    carregarPontos(lista, qtde);
    imprimeLista(lista);
    liberaLista(lista);
}