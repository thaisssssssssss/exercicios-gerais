#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "movel.h"
#include "fila.h"

int Compara(char *c1, char *c2){
    return (strcmp(c1, c2) == 0);
}

int main(){
    Fila *f = FilaConstruct();
    int op, i;
    scanf("%d", &op);
    for(i = 0; i < op; i++){
        char executar[50];
        scanf("%s", executar);

        if(Compara(executar, "ENTRADA")){
            tMovel *m = LeMovel();
            FilaPush(f, m);
            //DestroiMovel(m);
        }
        else if(Compara(executar, "PRODUZIR")){
            tMovel *m = FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
    }
    FilaDestroy(f, DestroiMovel);
}