#include <stdio.h>
#include "vetor.h"


int add(int n1, int n2){
    return n1 + n2;
}

int mult(int n1, int n2){
    return n1 * n2;
}

int main(){
    Vetor v;
    LeVetor(&v);
    printf("Soma: %d\n", AplicarOperacaoVetor(&v, add));
    printf("Produto: %d\n", AplicarOperacaoVetor(&v, mult));
}