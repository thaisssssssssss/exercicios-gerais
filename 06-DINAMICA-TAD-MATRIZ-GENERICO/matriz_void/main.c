#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void) {
  struct matriz *m;
  
  m = inicializaMatriz(5, 3, sizeof(char*));
  char a = 'a';
  for (int i=0; i < 5; i++) {
    for (int j =0; j < 3; j++){
      char a = 'a' + j + i;
      atribuiElemMatriz(m, i, j, &(a), TIPO_CHAR);
    }
  }

  imprimeMatriz(m,TIPO_CHAR);

  freeMatriz(m);

  return 0;
}