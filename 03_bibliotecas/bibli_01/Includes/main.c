#include <stdio.h>
#include "esfera_utils.h"

int main(int argc, char *argv[]){
    FILE *arqEntrada, *arqSaida;

  char leEntrada[1100];
  char fazSaida[1100];

  sprintf(fazSaida, "%s/saida/saida.txt", argv[1]);
  sprintf(leEntrada, "%s/entrada.txt", argv[1]);
  
  arqEntrada = fopen(leEntrada, "r");
  arqSaida = fopen(fazSaida, "w");

    float raio;
    float v, a;
    fscanf(arqEntrada, "%f", &raio);
    //scanf("%f", &raio);

    v = calcula_volume(raio);
    a = calcula_area(raio);

    //printf("Area: %.2f\nVolume: %.2f", a, v);

    fprintf(arqSaida, "Area: %.2f\nVolume: %.2f", a, v);

  fclose(arqEntrada);
  fclose(arqSaida);

    return 0;
}