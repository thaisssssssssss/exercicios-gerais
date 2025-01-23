#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(){
    int l, c;
    scanf("%d %d", &l, &c);
    int **matriz = CriaMatriz(l, c);
    LeMatriz(matriz, l, c);
    ImprimeMatrizTransposta(matriz, l, c);
    LiberaMatriz(matriz, l);
    return 0;
}