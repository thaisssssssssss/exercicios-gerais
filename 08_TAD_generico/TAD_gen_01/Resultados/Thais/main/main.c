#include <stdlib.h>
#include <stdio.h>
#include "tadgen.h"

int main(){
    int tipo, qtd;
    printf("tad_gen_01\n");
    scanf("%d %d", &tipo, &qtd);
    printf("Digite o tipo e numero de elementos: \n");
    tGeneric *g = CriaGenerico(tipo, qtd);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);
    return 0;
}